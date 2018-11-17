/**
 * 
 */

import java.io.File;
import java.io.PrintStream;
import java.nio.file.Files;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Arrays;
import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;

import org.apache.commons.text.StringEscapeUtils;
/**
 * @author Christhian
 *
 */
public class Indexer{
	
	public static MinHash minHash = null;
	
	/**
	 * Clase contenedor
	 */
	public static class Container implements Comparable<Container>{
		public int id;
		public int rep;
		public double sim;
		
		public Container(int id, double similarity){
			this.id = id;
			this.rep = 0;
			this.sim = similarity;
		}
		
		public Container(int id, int reputation, double similarity){
			this.id = id;
			this.rep = reputation;
			this.sim = similarity;
		}

		@Override
		public int compareTo(Container c) {
			int value = (int) ((c.sim - this.sim)*1000000);
			if (value != 0)
				return value;
			else 
				return c.rep - this.rep;
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		// Log FILE
		PrintStream ps = null;
		try {
			ps = new PrintStream("test.log");
			System.setOut(ps);
		} catch (Exception e) {
			e.printStackTrace();
			return;
		}
		
		// Busca el Driver
		try { 
			Class.forName("org.postgresql.Driver");
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
			ps.close();
			return;
		}
		
		// Establece la Conexion
		//System.out.println("------------ Conectando con el Servidor ------------");
		Connection conn = null;
		Statement st = null;
		ResultSet r = null;
		try {
			conn = DriverManager.getConnection(
				"jdbc:postgresql://127.0.0.1:5432/StackOverflow", "postgres", "pass");
			st = conn.createStatement();
		} catch (SQLException e) {
			try {
				conn.close();
			} catch (SQLException e1) {
				e1.printStackTrace();
			}
			System.out.println("No se ha podido establecer la conexion con el servidor.");
			e.printStackTrace();
			ps.close();
			return;
		}
		
		// Obteniendo valores iniciales
		//System.out.println("------------ Obteniendo valores iniciales ------------");
		Integer[] coefs0 = null, coefs1 = null;
		try {
			r = st.executeQuery("SELECT * FROM minHash");
			if (r.next()) {
				coefs0 = (Integer[]) r.getArray("coefs0").getArray();
				coefs1 = (Integer[]) r.getArray("coefs1").getArray();
			}
			r.close();
		} catch(SQLException e) {
			try {
				st.close();
				conn.close();
			} catch (SQLException e1) {
				e1.printStackTrace();
			}
			System.out.println("No se ha podido leer la base de datos.");
			e.printStackTrace();
			ps.close();
			return;
		}
		
		// Estableciendo firmas
		if (coefs0 != null && coefs1 != null)
			minHash = new MinHash(coefs0, coefs1);
		else {
			minHash = new MinHash();
			try {
				st.execute("DROP TABLE IF EXISTS minHash");
				st.execute("CREATE TABLE minHash (coefs0 INTEGER[], coefs1 INTEGER[])");
				st.executeUpdate("INSERT INTO minHash VALUES(ARRAY"+
						Arrays.toString(minHash.getCoefs0())+", ARRAY"+
						Arrays.toString(minHash.getCoefs1())+")");
			} catch (SQLException e) {
				try {
					st.close();
					conn.close();
				} catch (SQLException e1) {
					e1.printStackTrace();
				}
				System.out.println("No se ha podido escribir en la base de datos.");
				e.printStackTrace();
				ps.close();
				return;
			}
		}
		
		// Obtiene los ejemplos
		System.out.println("------------ Leyendo conjunto1 ------------");
		File folder = new File("conjunto1");
		
		int c = 0;
		int ii = 0;
		int[] rank = {1000,0,0,0,0};
		long ptime = 0;
		long time0 = 0;
		long time1 = 0;
		long time2 = 0;
		long time3 = 0;
		long total = 0;
		for (File f: folder.listFiles(f -> f.isFile())){
			try {
				// PREPROCESSING TIME
				ptime -= System.nanoTime();
				
				// Read File
				String code = new String(Files.readAllBytes(f.toPath()), "utf8");
				// FROM XML...
				code = StringEscapeUtils.unescapeXml(code);
				// FROM HTML
				code = StringEscapeUtils.unescapeHtml4(code);

				// REMOVE PREPROCESOR DIRECTIVES
				code = code.replaceAll("(?m)^\\s*?#.*?$\\n", "");
				
				ptime += System.nanoTime();

				// TOTAL TIME
				total -= System.nanoTime();

				// SIGNATURE CALCULATION TIME
				time0 -= System.nanoTime();
				
				int[] signature = minHash.signature(new Tokenizer(code).getHashSet());
				
				time0 += System.nanoTime();
				
				// LSH QUERY TIME
				time1 -= System.nanoTime();

				r = st.executeQuery("SELECT id, signature FROM codes NATURAL JOIN get_lsh1(ARRAY"
						+ Arrays.toString(signature) + ")");
				
				time1 += System.nanoTime();
				
				LinkedList<Container> lsh_pairs = new LinkedList<Container>();
				Integer[] other_sign;
				double sim;
				
				// MinHash CALCULATION TIME
				time2 -= System.nanoTime();
				
				while (r.next()) {
					// Count candidates
					c++;
					
					other_sign = (Integer[]) r.getArray("signature").getArray();
					sim = minHash.similarity(signature, other_sign);
					
					if (sim >= 0.5)
						lsh_pairs.add(new Container(r.getInt("id"), 0, sim));
				}
				r.close();
				
				time2 += System.nanoTime();
				
				// ORDER CALCULATION TIME
				time3 -= System.nanoTime();
				
				Collections.sort(lsh_pairs);
				
				time3 += System.nanoTime();
				
				String name = com.google.common.io.Files.
						getNameWithoutExtension(f.getName());
				int id  = Integer.parseInt(name);
				
				total += System.nanoTime();
				
				Iterator<Container> iter = lsh_pairs.iterator();
				int i = 0;
				
				// Total Rank
				while (iter.hasNext()){
					i++;
					if (iter.next().id == id){
						rank[0] -= 1;
						if (i == 1)
							rank[1] += 1;
						else
							if(i <= 10)
								rank[2] += 1;
							else
								rank[3] += 1;
						break;
					}
				}
				System.out.println(ii/10.0 + " --- " + name + " --- " + i + " --- " + total);
				ii++;
			} catch (Exception e) {
				try {
					st.close();
					conn.close();
				} catch (SQLException e1) {
					e1.printStackTrace();
				}
				System.out.println("No se ha podido leer la base de datos.");
				e.printStackTrace();
				ps.close();
				return;
			}
		}
		
		System.out.println("No encontrados: " + rank[0]);
		System.out.println("Eencontrados Rank 1: " + rank[1]);
		System.out.println("Eencontrados Rank 2: " + rank[2]);
		System.out.println("Eencontrados Rank 3: " + rank[3]);
		System.out.println("Eencontrados Rank 4: " + rank[4]);
		
		System.out.println("Tiempo promedio MinHash (ns):" + time0/1000.0);
		System.out.println("Candidatos promedio:" + c/1000.0);
		System.out.println("Tiempo promedio LSH (ns):" + time1/1000.0);
		System.out.println("Tiempo promedio firmas (ns):" + time2/1000.0);
		System.out.println("Tiempo promedio ord (ns):" + time3/1000.0);
		System.out.println("Tiempo promedio total (ns):" + total/1000.0);

		System.out.println("Tiempo total MinHash (ns):" + time0);
		System.out.println("Candidatos total" + c);
		System.out.println("Tiempo total LSH (ns):" + time1);
		System.out.println("Tiempo total firmas (ns):" + time2);
		System.out.println("Tiempo total ord (ns):" + time3);
		System.out.println("Tiempo total total (ns):" + total);
		
		// Obtiene los ejemplos
		System.out.println("------------ Leyendo conjunto2 ------------");
		folder = new File("conjunto2");
		
		for (File f: folder.listFiles(f -> f.isFile())){
			try {				
				// Read File
				String code = new String(Files.readAllBytes(f.toPath()), "utf8");

				// REMOVE PREPROCESOR DIRECTIVES
				code = code.replaceAll("(?m)^\\s*?#.*?$\\n", "");
								
				int[] signature = minHash.signature(new Tokenizer(code).getHashSet());
				
				r = st.executeQuery("SELECT id, signature FROM codes NATURAL JOIN get_lsh1(ARRAY"
						+ Arrays.toString(signature) + ")");
				
				LinkedList<Container> lsh_pairs = new LinkedList<Container>();
				Integer[] other_sign;
				double sim;
				
				while (r.next()) {
					other_sign = (Integer[]) r.getArray("signature").getArray();
					sim = minHash.similarity(signature, other_sign);
					
					if (sim >= 0.5)
						lsh_pairs.add(new Container(r.getInt("id"), 0, sim));
				}
				r.close();
				
				Collections.sort(lsh_pairs);
				System.out.println(" --- " + f.getName() + " --- ");
				
				Iterator<Container> iter = lsh_pairs.iterator();
				// Total Rank
				if (iter.hasNext()){
					sim = iter.next().sim * 100;
					if (sim >= 95.0)
						System.out.println("RANK1");
					else
						if(sim >= 85.0)
							System.out.println("RANK2");
						else
							if(sim >= 70.0)
								System.out.println("RANK3");
							else
								System.out.println("RANK4");
				} else
					System.out.println("NORANK");
			} catch (Exception e) {
				try {
					st.close();
					conn.close();
				} catch (SQLException e1) {
					e1.printStackTrace();
				}
				System.out.println("No se ha podido leer la base de datos.");
				e.printStackTrace();
				ps.close();
				return;
			}
		}
		
		// Obtiene los ejemplos
				System.out.println("------------ Leyendo conjunto3 ------------");
				folder = new File("conjunto3");
				
				for (File f: folder.listFiles(f -> f.isFile())){
					try {				
						// Read File
						String code = new String(Files.readAllBytes(f.toPath()), "utf8");

						// REMOVE PREPROCESOR DIRECTIVES
						code = code.replaceAll("(?m)^\\s*?#.*?$\\n", "");
										
						int[] signature = minHash.signature(new Tokenizer(code).getHashSet());
						
						r = st.executeQuery("SELECT id, signature FROM codes NATURAL JOIN get_lsh1(ARRAY"
								+ Arrays.toString(signature) + ")");
						
						LinkedList<Container> lsh_pairs = new LinkedList<Container>();
						Integer[] other_sign;
						double sim;
						
						while (r.next()) {
							other_sign = (Integer[]) r.getArray("signature").getArray();
							sim = minHash.similarity(signature, other_sign);
							
							if (sim >= 0.5)
								lsh_pairs.add(new Container(r.getInt("id"), 0, sim));
						}
						r.close();
						
						Collections.sort(lsh_pairs);
						
						Iterator<Container> iter = lsh_pairs.iterator();
						System.out.println(" --- " + f.getName() + " --- ");
						Container con;
						int i = 0;
						// Status
						while (iter.hasNext()) {
							i++;
							con = iter.next();
							sim = con.sim * 100;
							r = st.executeQuery("WITH r AS (SELECT post id FROM postcodes WHERE code = "+con.id+") "
									+ "SELECT p1.id, p1.posttypeid, p1.score, coalesce(p1.title, p2.title) title "
									+ "FROM r natural join posts p1 left join posts p2 ON p2.id = p1.parentid");
							
							if (r.next()){
								String s = r.getString("title");
								s = StringEscapeUtils.unescapeXml(s).substring(0,Math.min(s.length(),50));
								if (r.getInt("posttypeid") == 1)
									System.out.println(i+") Q:"+s+" ("+r.getInt("score")+") "+ sim + "% "+r.getInt("id"));
								else
									System.out.println(i+") A:"+s+" ("+r.getInt("score")+") "+ sim + "% "+r.getInt("id"));
							}else 
								System.out.println("Error: post "+con.id+" not found.");
							r.close();

							if (i == 10)
								break;
						}
					} catch (Exception e) {
						try {
							st.close();
							conn.close();
						} catch (SQLException e1) {
							e1.printStackTrace();
						}
						System.out.println("No se ha podido leer la base de datos.");
						e.printStackTrace();
						ps.close();
						return;
					}
				}
		
		try {
			st.close();
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}

		ps.close();
	}
}
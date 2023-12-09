import java.io.*;  
  
public class FileHandling {  
    public static void main(String[] args) {  
        try {  
            BufferedReader consoleReader = new BufferedReader(new InputStreamReader(System.in));  
            System.out.print("Enter the text to write to a file: ");  
            String text = consoleReader.readLine();  
  
            FileWriter fileWriter = new FileWriter("input.txt");  
            BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);  
            bufferedWriter.write(text);  
            bufferedWriter.close();  
            fileWriter.close();  
  
            FileReader fileReader = new FileReader("input.txt");  
            BufferedReader bufferedReader = new BufferedReader(fileReader);  
  
            FileWriter fileWriter2 = new FileWriter("output.txt");  
            BufferedWriter bufferedWriter2 = new BufferedWriter(fileWriter2);  
  
            String line = bufferedReader.readLine();  
            while (line != null) {  
                bufferedWriter2.write(line);  
                bufferedWriter2.newLine();  
                line = bufferedReader.readLine();  
            }  
            bufferedReader.close();  
            fileReader.close();  
            bufferedWriter2.close();  
            fileWriter2.close();  
            System.out.println("Copying sucessfull");  
  
            FileReader fileReader2 = new FileReader("output.txt");  
            BufferedReader bufferedReader2 = new BufferedReader(fileReader2);  
            line = bufferedReader2.readLine();  
            System.out.println("Content from output file: ");  
            while (line != null) {  
                System.out.println(line);  
                line = bufferedReader2.readLine();  
            }  
            bufferedReader2.close();  
            fileReader2.close();  
        } catch (FileNotFoundException e) {  
            System.out.println("File not found: " + e.getMessage());  
        } catch (IOException e) {  
            System.out.println("IO Exception: " + e.getMessage());  
        }  
    }  
}

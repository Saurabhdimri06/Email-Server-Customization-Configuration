package shellwrapper;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class RunningSS {

    public static void console() {

        ProcessBuilder processBuilder = new ProcessBuilder();
        // Windows
        String s = "echo this is some command";
        processBuilder.command("cmd.exe", "/c", s);
        
        try {
        	//Running the process builder to compile the script
            Process process = processBuilder.start();
            
            //Allocation the buffer reader to read the script
            BufferedReader reader =
                    new BufferedReader(new InputStreamReader(process.getInputStream()));

            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }

            int exitCode = process.waitFor();
            System.out.println("\nExited with error code : " + exitCode);

        } catch (IOException e) {
            e.printStackTrace();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }

}

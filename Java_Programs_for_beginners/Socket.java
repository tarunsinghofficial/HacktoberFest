package com.company;
//package com.company;

import java.io.DataInputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;
class Client {     // Client server
    public static void main(String[] args) {
        try {
            Socket client = new Socket("127.0.0.1",5000);
            DataOutputStream out = new DataOutputStream(client.getOutputStream());
            out.writeInt(100);
            System.out.println("Data Sent to the server!!!!");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}


class FacebookServer {  //Server socket
    public static void main(String[] args) {
        try {
            ServerSocket server = new ServerSocket(5000);
            System.out.println("Server is listening!!!");
            Socket socket= server.accept();
            System.out.println("Server is connected!!!");
            DataInputStream in = new DataInputStream(socket.getInputStream());
            System.out.println(in.readInt());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace RemoteCarControl.Services
{
    public class Connection
    {
        UdpClient udpServer = new UdpClient(11000);
        IPEndPoint remoteEP = new IPEndPoint(IPAddress.Parse("192.168.1.166"), 8888) ;
        Form1 form1;
        ICrypto crypto;

        public Connection(Form1 form1, ICrypto crypto)
        {
            this.form1 = form1;
            this.crypto = crypto;
            udpServer.BeginReceive(new AsyncCallback(startUpdListener), null);
        }

        public void sendData(string msg)
        {

            msg = crypto.encrypt(msg);
            byte[] send_buffer = Encoding.ASCII.GetBytes(msg);
            udpServer.Send(send_buffer, remoteEP); 

        }


        public  void startUpdListener(IAsyncResult res)
        {
            byte[] received = udpServer.EndReceive(res, ref remoteEP);
            string msg = Encoding.UTF8.GetString(received);
            msg = crypto.encrypt(msg);
            form1.UdpListener(msg);
            udpServer.BeginReceive(new AsyncCallback(startUpdListener), null);       
        }

    }
}

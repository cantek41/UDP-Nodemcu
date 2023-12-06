using RemoteCarControl.Services;
using System.Text;

namespace RemoteCarControl
{
    public partial class Form1 : Form
    {
        Connection con;
        public Form1()
        {
            TextBox.CheckForIllegalCrossThreadCalls = false;
            InitializeComponent();
            con = new Connection(this, new MyCrypto());
        }

        private void Sent_Click(object sender, EventArgs e)
        {
            con.sendData("backward");
        }
        public void UdpListener(string recivedData)
        {
            if (recivedData.Last() == 'T')
            {
                temp.Text = recivedData;
            }
            else if (recivedData.Last() == 'H')
            {
                humi.Text = recivedData;
            }
            else
                mesure.Text =  recivedData;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            con.sendData("forward");

        }

        private void button4_Click(object sender, EventArgs e)
        {
            con.sendData("stop");
        }
        private void button2_Click(object sender, EventArgs e)
        {
            con.sendData("left");
        }
        private void button3_Click(object sender, EventArgs e)
        {
            con.sendData("right");
        }
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode.Equals(Keys.W))
            {
                button1_Click(sender, e);
            }
            else if (e.KeyCode.Equals(Keys.S))
            {
                Sent_Click(sender, e);
            }
            else if (e.KeyCode.Equals(Keys.D))
            {
                button3_Click(sender, e);
            }
            else if (e.KeyCode.Equals(Keys.A))
            {
                button2_Click(sender, e);
            }
            else if (e.KeyCode.Equals(Keys.Z))
            {
                button4_Click(sender, e);
            }
        }
    }
}
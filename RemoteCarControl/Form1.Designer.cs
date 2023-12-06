namespace RemoteCarControl
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            Sent = new Button();
            humi = new TextBox();
            temp = new TextBox();
            button1 = new Button();
            button2 = new Button();
            button3 = new Button();
            button4 = new Button();
            label1 = new Label();
            label2 = new Label();
            mesure = new TextBox();
            label3 = new Label();
            SuspendLayout();
            // 
            // Sent
            // 
            Sent.Location = new Point(283, 57);
            Sent.Name = "Sent";
            Sent.Size = new Size(94, 29);
            Sent.TabIndex = 0;
            Sent.Text = "backward";
            Sent.UseVisualStyleBackColor = true;
            Sent.Click += Sent_Click;
            // 
            // humi
            // 
            humi.Enabled = false;
            humi.Location = new Point(40, 57);
            humi.Name = "humi";
            humi.Size = new Size(125, 27);
            humi.TabIndex = 1;
            // 
            // temp
            // 
            temp.Enabled = false;
            temp.Location = new Point(40, 104);
            temp.Name = "temp";
            temp.Size = new Size(125, 27);
            temp.TabIndex = 1;
            // 
            // button1
            // 
            button1.Location = new Point(183, 57);
            button1.Name = "button1";
            button1.Size = new Size(94, 29);
            button1.TabIndex = 2;
            button1.Text = "forward";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // button2
            // 
            button2.Location = new Point(183, 92);
            button2.Name = "button2";
            button2.Size = new Size(94, 29);
            button2.TabIndex = 5;
            button2.Text = "left";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // button3
            // 
            button3.Location = new Point(283, 92);
            button3.Name = "button3";
            button3.Size = new Size(94, 29);
            button3.TabIndex = 4;
            button3.Text = "right";
            button3.UseVisualStyleBackColor = true;
            button3.Click += button3_Click;
            // 
            // button4
            // 
            button4.Location = new Point(229, 127);
            button4.Name = "button4";
            button4.Size = new Size(94, 29);
            button4.TabIndex = 6;
            button4.Text = "stop";
            button4.UseVisualStyleBackColor = true;
            button4.Click += button4_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(40, 34);
            label1.Name = "label1";
            label1.Size = new Size(41, 20);
            label1.TabIndex = 7;
            label1.Text = "Hum";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(40, 87);
            label2.Name = "label2";
            label2.Size = new Size(46, 20);
            label2.TabIndex = 7;
            label2.Text = "Temp";
            // 
            // mesure
            // 
            mesure.Enabled = false;
            mesure.Location = new Point(40, 160);
            mesure.Name = "mesure";
            mesure.Size = new Size(125, 27);
            mesure.TabIndex = 1;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(40, 137);
            label3.Name = "label3";
            label3.Size = new Size(36, 20);
            label3.TabIndex = 7;
            label3.Text = "Mes";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(402, 251);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(button4);
            Controls.Add(button2);
            Controls.Add(button3);
            Controls.Add(button1);
            Controls.Add(mesure);
            Controls.Add(temp);
            Controls.Add(humi);
            Controls.Add(Sent);
            KeyPreview = true;
            Name = "Form1";
            Text = "Form1";
            KeyDown += Form1_KeyDown;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button Sent;
        private TextBox humi;
        private TextBox temp;
        private Button button1;
        private Button button2;
        private Button button3;
        private Button button4;
        private Label label1;
        private Label label2;
        private TextBox mesure;
        private Label label3;
    }
}
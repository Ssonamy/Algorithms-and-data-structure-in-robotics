namespace LibraryCatalog
{
    partial class ConnectionForm
    {
        private System.ComponentModel.IContainer components = null;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        private void InitializeComponent()
        {
            txtHost = new TextBox();
            txtPort = new TextBox();
            txtUsername = new TextBox();
            txtPassword = new TextBox();
            txtDatabase = new TextBox();
            btnConnect = new Button();
            SuspendLayout();
            // 
            // txtHost
            // 
            txtHost.Location = new Point(12, 12);
            txtHost.Name = "txtHost";
            txtHost.PlaceholderText = "Host";
            txtHost.Size = new Size(260, 31);
            txtHost.TabIndex = 0;
            // 
            // txtPort
            // 
            txtPort.Location = new Point(12, 38);
            txtPort.Name = "txtPort";
            txtPort.PlaceholderText = "Port";
            txtPort.Size = new Size(260, 31);
            txtPort.TabIndex = 1;
            // 
            // txtUsername
            // 
            txtUsername.Location = new Point(12, 64);
            txtUsername.Name = "txtUsername";
            txtUsername.PlaceholderText = "Username";
            txtUsername.Size = new Size(260, 31);
            txtUsername.TabIndex = 2;
            // 
            // txtPassword
            // 
            txtPassword.Location = new Point(12, 90);
            txtPassword.Name = "txtPassword";
            txtPassword.PlaceholderText = "Password";
            txtPassword.Size = new Size(260, 31);
            txtPassword.TabIndex = 3;
            txtPassword.UseSystemPasswordChar = true;
            // 
            // txtDatabase
            // 
            txtDatabase.Location = new Point(12, 116);
            txtDatabase.Name = "txtDatabase";
            txtDatabase.PlaceholderText = "Database";
            txtDatabase.Size = new Size(260, 31);
            txtDatabase.TabIndex = 4;
            // 
            // btnConnect
            // 
            btnConnect.Location = new Point(12, 181);
            btnConnect.Name = "btnConnect";
            btnConnect.Size = new Size(260, 43);
            btnConnect.TabIndex = 5;
            btnConnect.Text = "Connect";
            btnConnect.UseVisualStyleBackColor = true;
            btnConnect.Click += btnConnect_Click;
            // 
            // ConnectionForm
            // 
            ClientSize = new Size(299, 263);
            Controls.Add(btnConnect);
            Controls.Add(txtDatabase);
            Controls.Add(txtPassword);
            Controls.Add(txtUsername);
            Controls.Add(txtPort);
            Controls.Add(txtHost);
            Name = "ConnectionForm";
            Text = "ConnectionForm";
            ResumeLayout(false);
            PerformLayout();
        }

        private System.Windows.Forms.TextBox txtHost;
        private System.Windows.Forms.TextBox txtPort;
        private System.Windows.Forms.TextBox txtUsername;
        private System.Windows.Forms.TextBox txtPassword;
        private System.Windows.Forms.TextBox txtDatabase;
        private System.Windows.Forms.Button btnConnect;
    }
}

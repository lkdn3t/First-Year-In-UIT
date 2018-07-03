namespace Math_Quiz
{
    partial class MathQuizForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.timeLabel = new System.Windows.Forms.Label();
            this.time2Label = new System.Windows.Forms.Label();
            this.plusLeftLabel = new System.Windows.Forms.Label();
            this.plusSignLabel = new System.Windows.Forms.Label();
            this.plusRightLabel = new System.Windows.Forms.Label();
            this.equalPlusSignLabel = new System.Windows.Forms.Label();
            this.sumNumeric = new System.Windows.Forms.NumericUpDown();
            this.diffNumeric = new System.Windows.Forms.NumericUpDown();
            this.equalMinusSignLabel = new System.Windows.Forms.Label();
            this.minusRightLabel = new System.Windows.Forms.Label();
            this.minusSignLabel = new System.Windows.Forms.Label();
            this.minusLeftLabel = new System.Windows.Forms.Label();
            this.productNumeric = new System.Windows.Forms.NumericUpDown();
            this.equalMultiSignLabel = new System.Windows.Forms.Label();
            this.multiRightLabel = new System.Windows.Forms.Label();
            this.multiSignLabel = new System.Windows.Forms.Label();
            this.multiLeftLabel = new System.Windows.Forms.Label();
            this.divisionNumeric = new System.Windows.Forms.NumericUpDown();
            this.equalDivideSignLabel = new System.Windows.Forms.Label();
            this.divideRightLabel = new System.Windows.Forms.Label();
            this.divideSignLabel = new System.Windows.Forms.Label();
            this.divideLeftLabel = new System.Windows.Forms.Label();
            this.startButton = new System.Windows.Forms.Button();
            this.timer = new System.Windows.Forms.Timer(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.sumNumeric)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.diffNumeric)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.productNumeric)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.divisionNumeric)).BeginInit();
            this.SuspendLayout();
            // 
            // timeLabel
            // 
            this.timeLabel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.timeLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.timeLabel.Location = new System.Drawing.Point(170, 18);
            this.timeLabel.Name = "timeLabel";
            this.timeLabel.Size = new System.Drawing.Size(189, 27);
            this.timeLabel.TabIndex = 0;
            this.timeLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // time2Label
            // 
            this.time2Label.AutoSize = true;
            this.time2Label.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.time2Label.Location = new System.Drawing.Point(73, 19);
            this.time2Label.Name = "time2Label";
            this.time2Label.Size = new System.Drawing.Size(80, 20);
            this.time2Label.TabIndex = 1;
            this.time2Label.Text = "Time Left";
            // 
            // plusLeftLabel
            // 
            this.plusLeftLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.plusLeftLabel.Location = new System.Drawing.Point(64, 79);
            this.plusLeftLabel.Name = "plusLeftLabel";
            this.plusLeftLabel.Size = new System.Drawing.Size(45, 30);
            this.plusLeftLabel.TabIndex = 2;
            this.plusLeftLabel.Text = "?";
            this.plusLeftLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // plusSignLabel
            // 
            this.plusSignLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.plusSignLabel.Location = new System.Drawing.Point(115, 79);
            this.plusSignLabel.Name = "plusSignLabel";
            this.plusSignLabel.Size = new System.Drawing.Size(45, 30);
            this.plusSignLabel.TabIndex = 3;
            this.plusSignLabel.Text = "+";
            this.plusSignLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // plusRightLabel
            // 
            this.plusRightLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.plusRightLabel.Location = new System.Drawing.Point(166, 79);
            this.plusRightLabel.Name = "plusRightLabel";
            this.plusRightLabel.Size = new System.Drawing.Size(45, 30);
            this.plusRightLabel.TabIndex = 4;
            this.plusRightLabel.Text = "?";
            this.plusRightLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // equalPlusSignLabel
            // 
            this.equalPlusSignLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.equalPlusSignLabel.Location = new System.Drawing.Point(217, 79);
            this.equalPlusSignLabel.Name = "equalPlusSignLabel";
            this.equalPlusSignLabel.Size = new System.Drawing.Size(45, 30);
            this.equalPlusSignLabel.TabIndex = 5;
            this.equalPlusSignLabel.Text = "=";
            this.equalPlusSignLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // sumNumeric
            // 
            this.sumNumeric.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.sumNumeric.Location = new System.Drawing.Point(268, 79);
            this.sumNumeric.Name = "sumNumeric";
            this.sumNumeric.Size = new System.Drawing.Size(90, 26);
            this.sumNumeric.TabIndex = 6;
            this.sumNumeric.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.sumNumeric.Enter += new System.EventHandler(this.answer_Enter);
            // 
            // diffNumeric
            // 
            this.diffNumeric.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.diffNumeric.Location = new System.Drawing.Point(268, 142);
            this.diffNumeric.Name = "diffNumeric";
            this.diffNumeric.Size = new System.Drawing.Size(90, 26);
            this.diffNumeric.TabIndex = 11;
            this.diffNumeric.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.diffNumeric.Enter += new System.EventHandler(this.answer_Enter);
            // 
            // equalMinusSignLabel
            // 
            this.equalMinusSignLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.equalMinusSignLabel.Location = new System.Drawing.Point(217, 142);
            this.equalMinusSignLabel.Name = "equalMinusSignLabel";
            this.equalMinusSignLabel.Size = new System.Drawing.Size(45, 30);
            this.equalMinusSignLabel.TabIndex = 10;
            this.equalMinusSignLabel.Text = "=";
            this.equalMinusSignLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // minusRightLabel
            // 
            this.minusRightLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.minusRightLabel.Location = new System.Drawing.Point(166, 142);
            this.minusRightLabel.Name = "minusRightLabel";
            this.minusRightLabel.Size = new System.Drawing.Size(45, 30);
            this.minusRightLabel.TabIndex = 9;
            this.minusRightLabel.Text = "?";
            this.minusRightLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // minusSignLabel
            // 
            this.minusSignLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.minusSignLabel.Location = new System.Drawing.Point(115, 142);
            this.minusSignLabel.Name = "minusSignLabel";
            this.minusSignLabel.Size = new System.Drawing.Size(45, 30);
            this.minusSignLabel.TabIndex = 8;
            this.minusSignLabel.Text = "-";
            this.minusSignLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // minusLeftLabel
            // 
            this.minusLeftLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.minusLeftLabel.Location = new System.Drawing.Point(64, 142);
            this.minusLeftLabel.Name = "minusLeftLabel";
            this.minusLeftLabel.Size = new System.Drawing.Size(45, 30);
            this.minusLeftLabel.TabIndex = 7;
            this.minusLeftLabel.Text = "?";
            this.minusLeftLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // productNumeric
            // 
            this.productNumeric.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.productNumeric.Location = new System.Drawing.Point(268, 207);
            this.productNumeric.Name = "productNumeric";
            this.productNumeric.Size = new System.Drawing.Size(90, 26);
            this.productNumeric.TabIndex = 16;
            this.productNumeric.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.productNumeric.Enter += new System.EventHandler(this.answer_Enter);
            // 
            // equalMultiSignLabel
            // 
            this.equalMultiSignLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.equalMultiSignLabel.Location = new System.Drawing.Point(217, 207);
            this.equalMultiSignLabel.Name = "equalMultiSignLabel";
            this.equalMultiSignLabel.Size = new System.Drawing.Size(45, 30);
            this.equalMultiSignLabel.TabIndex = 15;
            this.equalMultiSignLabel.Text = "=";
            this.equalMultiSignLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // multiRightLabel
            // 
            this.multiRightLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.multiRightLabel.Location = new System.Drawing.Point(166, 207);
            this.multiRightLabel.Name = "multiRightLabel";
            this.multiRightLabel.Size = new System.Drawing.Size(45, 30);
            this.multiRightLabel.TabIndex = 14;
            this.multiRightLabel.Text = "?";
            this.multiRightLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // multiSignLabel
            // 
            this.multiSignLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.multiSignLabel.Location = new System.Drawing.Point(115, 207);
            this.multiSignLabel.Name = "multiSignLabel";
            this.multiSignLabel.Size = new System.Drawing.Size(45, 30);
            this.multiSignLabel.TabIndex = 13;
            this.multiSignLabel.Text = "x";
            this.multiSignLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // multiLeftLabel
            // 
            this.multiLeftLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.multiLeftLabel.Location = new System.Drawing.Point(64, 207);
            this.multiLeftLabel.Name = "multiLeftLabel";
            this.multiLeftLabel.Size = new System.Drawing.Size(45, 30);
            this.multiLeftLabel.TabIndex = 12;
            this.multiLeftLabel.Text = "?";
            this.multiLeftLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // divisionNumeric
            // 
            this.divisionNumeric.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.divisionNumeric.Location = new System.Drawing.Point(268, 272);
            this.divisionNumeric.Name = "divisionNumeric";
            this.divisionNumeric.Size = new System.Drawing.Size(90, 26);
            this.divisionNumeric.TabIndex = 21;
            this.divisionNumeric.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.divisionNumeric.Enter += new System.EventHandler(this.answer_Enter);
            // 
            // equalDivideSignLabel
            // 
            this.equalDivideSignLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.equalDivideSignLabel.Location = new System.Drawing.Point(217, 272);
            this.equalDivideSignLabel.Name = "equalDivideSignLabel";
            this.equalDivideSignLabel.Size = new System.Drawing.Size(45, 30);
            this.equalDivideSignLabel.TabIndex = 20;
            this.equalDivideSignLabel.Text = "=";
            this.equalDivideSignLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // divideRightLabel
            // 
            this.divideRightLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.divideRightLabel.Location = new System.Drawing.Point(166, 272);
            this.divideRightLabel.Name = "divideRightLabel";
            this.divideRightLabel.Size = new System.Drawing.Size(45, 30);
            this.divideRightLabel.TabIndex = 19;
            this.divideRightLabel.Text = "?";
            this.divideRightLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // divideSignLabel
            // 
            this.divideSignLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.divideSignLabel.Location = new System.Drawing.Point(115, 272);
            this.divideSignLabel.Name = "divideSignLabel";
            this.divideSignLabel.Size = new System.Drawing.Size(45, 30);
            this.divideSignLabel.TabIndex = 18;
            this.divideSignLabel.Text = "÷";
            this.divideSignLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // divideLeftLabel
            // 
            this.divideLeftLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.divideLeftLabel.Location = new System.Drawing.Point(64, 272);
            this.divideLeftLabel.Name = "divideLeftLabel";
            this.divideLeftLabel.Size = new System.Drawing.Size(45, 30);
            this.divideLeftLabel.TabIndex = 17;
            this.divideLeftLabel.Text = "?";
            this.divideLeftLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // startButton
            // 
            this.startButton.AutoSize = true;
            this.startButton.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.startButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.startButton.Location = new System.Drawing.Point(77, 329);
            this.startButton.Name = "startButton";
            this.startButton.Size = new System.Drawing.Size(281, 30);
            this.startButton.TabIndex = 22;
            this.startButton.Text = "Start the Quiz!";
            this.startButton.UseVisualStyleBackColor = true;
            this.startButton.Click += new System.EventHandler(this.startButton_Click);
            // 
            // timer
            // 
            this.timer.Interval = 1000;
            this.timer.Tick += new System.EventHandler(this.timer_Tick);
            // 
            // MathQuizForm
            // 
            this.AcceptButton = this.startButton;
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(432, 389);
            this.Controls.Add(this.startButton);
            this.Controls.Add(this.divisionNumeric);
            this.Controls.Add(this.equalDivideSignLabel);
            this.Controls.Add(this.divideRightLabel);
            this.Controls.Add(this.divideSignLabel);
            this.Controls.Add(this.divideLeftLabel);
            this.Controls.Add(this.productNumeric);
            this.Controls.Add(this.equalMultiSignLabel);
            this.Controls.Add(this.multiRightLabel);
            this.Controls.Add(this.multiSignLabel);
            this.Controls.Add(this.multiLeftLabel);
            this.Controls.Add(this.diffNumeric);
            this.Controls.Add(this.equalMinusSignLabel);
            this.Controls.Add(this.minusRightLabel);
            this.Controls.Add(this.minusSignLabel);
            this.Controls.Add(this.minusLeftLabel);
            this.Controls.Add(this.sumNumeric);
            this.Controls.Add(this.equalPlusSignLabel);
            this.Controls.Add(this.plusRightLabel);
            this.Controls.Add(this.plusSignLabel);
            this.Controls.Add(this.plusLeftLabel);
            this.Controls.Add(this.time2Label);
            this.Controls.Add(this.timeLabel);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.MaximizeBox = false;
            this.Name = "MathQuizForm";
            this.Text = "Math Quiz";
            ((System.ComponentModel.ISupportInitialize)(this.sumNumeric)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.diffNumeric)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.productNumeric)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.divisionNumeric)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label timeLabel;
        private System.Windows.Forms.Label time2Label;
        private System.Windows.Forms.Label plusLeftLabel;
        private System.Windows.Forms.Label plusSignLabel;
        private System.Windows.Forms.Label plusRightLabel;
        private System.Windows.Forms.Label equalPlusSignLabel;
        private System.Windows.Forms.NumericUpDown sumNumeric;
        private System.Windows.Forms.NumericUpDown diffNumeric;
        private System.Windows.Forms.Label equalMinusSignLabel;
        private System.Windows.Forms.Label minusRightLabel;
        private System.Windows.Forms.Label minusSignLabel;
        private System.Windows.Forms.Label minusLeftLabel;
        private System.Windows.Forms.NumericUpDown productNumeric;
        private System.Windows.Forms.Label equalMultiSignLabel;
        private System.Windows.Forms.Label multiRightLabel;
        private System.Windows.Forms.Label multiSignLabel;
        private System.Windows.Forms.Label multiLeftLabel;
        private System.Windows.Forms.NumericUpDown divisionNumeric;
        private System.Windows.Forms.Label equalDivideSignLabel;
        private System.Windows.Forms.Label divideRightLabel;
        private System.Windows.Forms.Label divideSignLabel;
        private System.Windows.Forms.Label divideLeftLabel;
        private System.Windows.Forms.Button startButton;
        private System.Windows.Forms.Timer timer;
    }
}


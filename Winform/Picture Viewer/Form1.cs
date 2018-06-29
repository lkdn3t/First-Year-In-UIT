using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Picture_Viewer
{
    public partial class PictureViewerForm : Form
    {
        public PictureViewerForm()
        {
            InitializeComponent();
        }

        private void closeButton_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void backgroundButton_Click(object sender, EventArgs e)
        {
            if (backgroundColorDialog.ShowDialog() == DialogResult.OK)
                pictureBox.BackColor = backgroundColorDialog.Color;
        }

        private void clearButton_Click(object sender, EventArgs e)
        {
            pictureBox.Image = null;
        }

        private void showButton_Click(object sender, EventArgs e)
        {
            if (pictureFileDialog.ShowDialog() == DialogResult.OK)
                pictureBox.Load(pictureFileDialog.FileName);
        }

        private void strectchCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            if (strectchCheckBox.Checked)
                pictureBox.SizeMode = PictureBoxSizeMode.StretchImage;
            else
                pictureBox.SizeMode = PictureBoxSizeMode.Normal;
        }
    }
}

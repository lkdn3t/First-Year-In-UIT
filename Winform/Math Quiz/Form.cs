using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Math_Quiz
{
    public partial class MathQuizForm : Form
    {
        Random rnd = new Random();
        int timeLeft;

        int leftPlusValue;
        int leftMinusValue;
        int leftMultiValue;
        int leftDivideValue;

        int rightPlusValue;
        int rightMinusValue;
        int rightMultiValue;
        int rightDivideValue;

        public MathQuizForm()
        {
            InitializeComponent();
        }

        public void StartTheQuiz()
        {
            // Generate a random add-operation
            leftPlusValue = rnd.Next(51);
            rightPlusValue = rnd.Next(51);
            plusLeftLabel.Text = leftPlusValue.ToString();
            plusRightLabel.Text = rightPlusValue.ToString();
            sumNumeric.Value = 0;

            // Generate a random subtract-operation
            leftMinusValue = rnd.Next(1, 100);
            rightMinusValue = rnd.Next(1, leftMinusValue);
            minusLeftLabel.Text = leftMinusValue.ToString();
            minusRightLabel.Text = rightMinusValue.ToString();
            diffNumeric.Value = 0;

            // Generate a random multiply-operation
            leftMultiValue = rnd.Next(1, 10);
            rightMultiValue = rnd.Next(1, 10);
            multiLeftLabel.Text = leftMultiValue.ToString();
            multiRightLabel.Text = rightMultiValue.ToString();
            productNumeric.Value = 0;

            // Generate a random divide-operation
            rightDivideValue = rnd.Next(1, 10);
            int resultDivideValue = rnd.Next(1, 10);
            leftDivideValue = rightDivideValue * resultDivideValue;
            divideLeftLabel.Text = leftDivideValue.ToString();
            divideRightLabel.Text = rightDivideValue.ToString();
            divisionNumeric.Value = 0;

            // Start the timer
            timeLeft = 30;
            timeLabel.BackColor = Color.White;
            timeLabel.Text = timeLeft + " seconds";
            timer.Start();
        }

        private bool CheckTheAnswer()
        {
            return leftPlusValue + rightPlusValue == sumNumeric.Value
                && leftMinusValue - rightMinusValue == diffNumeric.Value
                && leftMultiValue * rightMultiValue == productNumeric.Value
                && leftDivideValue / rightDivideValue == divisionNumeric.Value;
        }

        private void startButton_Click(object sender, EventArgs e)
        {
            StartTheQuiz();
            startButton.Enabled = false;
        }

        private void timer_Tick(object sender, EventArgs e)
        {
            if (CheckTheAnswer())
            {
                timer.Stop();
                MessageBox.Show("You got all the answer right!");
                startButton.Enabled = true;
            }

            if (timeLeft > 0)
            {
                timeLeft = timeLeft - 1;
                timeLabel.Text = timeLeft + " seconds";
            }
            else
            {
                timer.Stop();
                timeLabel.BackColor = Color.LightYellow;
                timeLabel.Text = "Time's up!";
                MessageBox.Show("You didn't finish the quiz in time.");
                sumNumeric.Value = leftPlusValue + rightPlusValue;
                startButton.Enabled = true;
            }
        }

        private void answer_Enter(object sender, EventArgs e)
        {
            // Select the whole answer in the NumericUpDown control.
            if (sender is NumericUpDown answerBox)
                answerBox.Select(0, answerBox.Value.ToString().Length);
        }
    }
}
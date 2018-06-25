using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string InputFilePath = @"C:\Users\PC\source\repos\ConsoleApp1\ConsoleApp1\KHAOSAT.INP";
            string OutputFilePath = @"C:\Users\PC\source\repos\ConsoleApp1\ConsoleApp1\KHAOSAT.OUT";

            AnalyzeFunction AnalyzeFunc = new AnalyzeFunction();
            AnalyzeFunc.Input(InputFilePath);
            AnalyzeFunc.Analyze(OutputFilePath);
            AnalyzeFunc.AnalyzeDerivative(OutputFilePath);
        }
    }
}
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApp1
{
    class AnalyzeFunction
    {
        public float _min { get; set; }
        public float _max { get; set; }
        public float _step { get; set; }

        private readonly F1_Function Func1 = new F1_Function();
        private readonly F2_Function Func2 = new F2_Function();
        private readonly F3_Function Func3 = new F3_Function();

        private readonly List<float> AnalyzeVar = new List<float>();

        public void Input(string FilePath)
        {
            float[] entries = Array.ConvertAll(File.ReadAllText(FilePath).Split(), float.Parse);

            Func1._k = entries[0];
            Func2._k = entries[1];
            Func3._k = entries[2];
            _min = entries[3];
            _max = entries[4];
            _step = entries[5];

            for (float i = _min; i <= _max; i += _step)
                AnalyzeVar.Add(i);
        }

        public void Analyze(string FilePath)
        {
            using (StreamWriter sw = new StreamWriter(FilePath))
            {
                foreach (float x in AnalyzeVar)
                    sw.Write("{0} ", x);
                sw.WriteLine();

                foreach (float x in AnalyzeVar)
                    sw.Write("{0} ", Func1.Calculate(x));
                sw.WriteLine();

                foreach (float x in AnalyzeVar)
                    sw.Write("{0} ", Func2.Calculate(x));
                sw.WriteLine();

                foreach (float x in AnalyzeVar)
                    sw.Write("{0} ", Func3.Calculate(x));
                sw.WriteLine();
            }
        }

        public void AnalyzeDerivative(string FilePath)
        {
            using (StreamWriter sw = new StreamWriter(FilePath, true))
            {
                foreach (float x in AnalyzeVar)
                    sw.Write("{0} ", Func1.CalDerivative(x));
                sw.WriteLine();

                foreach (float x in AnalyzeVar)
                    sw.Write("{0} ", Func2.CalDerivative(x));
                sw.WriteLine();

                foreach (float x in AnalyzeVar)
                    sw.Write("{0} ", Func3.CalDerivative(x));
            }
        }
    }
}

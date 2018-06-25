using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    public abstract class Function
    {
        public float _k { get; set; }
        public abstract float Calculate(float x);
        public abstract float CalDerivative(float x);
    }

    //f1(x) = kx - 3
    class F1_Function : Function
    { 
        public override float Calculate(float x)
        {
            return _k * x - 3;
        }

        public override float CalDerivative(float x)
        {
            return _k;
        }
    }

    //f2(x) = -3x^2 + kx
    class F2_Function: Function
    {
        public override float Calculate(float x)
        {
            return -3 * x * x + _k * x;
        }

        public override float CalDerivative(float x)
        {
            return -6 * x + _k;
        }
    }

    //f3(x) = 7x^3 + kx^2 - 5
    class F3_Function : Function
    {
        public override float Calculate(float x)
        {
            return 7 * x * x * x + _k * x * x - 5;
        }

        public override float CalDerivative(float x)
        {
            return 21 * x * x + 2 * _k * x;
        }
    }
}
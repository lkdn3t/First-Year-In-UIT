using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    //Mỗi gia súc có lượng sữa, số con mỗi lứa và tiếng kêu riêng
    //Sinh ngẫu nhiên các thuộc tính mỗi gia súc (Bò, Cừu, Dê) theo mô tả.

    public class Cattle
    {
        public int Milk { get; set; }
        public int Children { get; set; }
        public string Noise { get; set; }
        
        public void MakeNoise()
        {
            Console.WriteLine(Noise);
        }

        public void GiveMilk()
        {
            Console.WriteLine("- Luong sua: " + Milk.ToString());
        }
        
        public void GiveBirth()
        {
            Console.WriteLine("- So con: " + Children.ToString());
        }

        public void Informate()
        {
            Console.Write("- Tieng keu: "); MakeNoise();
            GiveMilk();
            GiveBirth();
        }
    }
    
    class Cow : Cattle
    {
        public Cow()
        {
            ListCattle.CowCounter++;
            Random rnd = new Random();
            Milk = rnd.Next(0, 21);
            Children = rnd.Next(1, 3);
            Noise = "Um bo!";
        }
    }

    class Sheep : Cattle
    {
        public Sheep()
        {
            ListCattle.SheepCounter++;
            Random rnd = new Random();
            Milk = rnd.Next(0, 6);
            Children = rnd.Next(2, 5);
            Noise = "Be be!";
        }
    }

    class Goat : Cattle
    {
        public Goat()
        {
            ListCattle.GoatCounter++;
            Random rnd = new Random();
            Milk = rnd.Next(0, 11);
            Children = rnd.Next(3, 5);
            Noise = "Beeee!";
        }
    }

    class ListCattle
    {
        public static int CowCounter = 0;
        public static int SheepCounter = 0;
        public static int GoatCounter = 0;

        private List<Cattle> LstCattle = new List<Cattle>(); 
        
        public void GetInformation()
        {
            //Nhập thông tin các gia súc trong trang trại
            //Bao gồm: số lượng từng loại và random các thông số cho từng gia súc

            Console.WriteLine("...Nhap thong tin gia suc trong trang trai...");
            int NumInput;

            Console.Write("- Nhap so luong bo: ");
            NumInput = int.Parse(Console.ReadLine());

            for (int i = 0; i < NumInput; i++)
                LstCattle.Add(new Cow());

            Console.Write("- Nhap so luong cuu: ");
            NumInput = int.Parse(Console.ReadLine());

            for (int i = 0; i < NumInput; i++)
                LstCattle.Add(new Sheep());

            Console.Write("- Nhap so luong de: ");
            NumInput = int.Parse(Console.ReadLine());

            for (int i = 0; i < NumInput; i++)
                LstCattle.Add(new Goat());
        }

        public void PutInformation()
        {
            //Xuất thông tin các gia súc trong trang trại
            //Bao gồm: số lượng mỗi loại và thông tin từng gia súc.

            Console.WriteLine("\n...Thong tin cac gia suc...");
            Console.WriteLine("- So luong bo: " + CowCounter.ToString());
            Console.WriteLine("- So luong cuu: " + SheepCounter.ToString());
            Console.WriteLine("- So luong de: " + GoatCounter.ToString());

            int counter = 1;
            foreach (Cattle cattle in LstCattle)
            {
                Console.WriteLine("\n[Thong tin gia suc thu " + (counter++).ToString() + "]");

                Console.Write("- Loai gia suc: ");
                if (cattle is Cow)
                    Console.WriteLine("Bo");
                else if (cattle is Sheep)
                    Console.WriteLine("Cuu");
                else
                    Console.WriteLine("De");

                cattle.Informate();
            }
        }
        
        public void MakeNoiseAll()
        {
            //Danh sách tiếng kêu tất cả gia súc khi đói

            Console.WriteLine("\n...Thong tin cac tieng keu thu duoc...");
            foreach (Cattle cattle in LstCattle)
                cattle.MakeNoise();
        }
        
        public void GiveBirthAll()
        {
            //Khi tất cả gia súc sinh con
            //Tính tổng số con từng loại và thêm vào danh sách gia súc

            int CowChildren = 0;
            int SheepChildren = 0;
            int GoatChildren = 0;

            foreach (Cattle cattle in LstCattle)
            {
                if (cattle is Cow)
                    CowChildren += cattle.Children;

                else if (cattle is Sheep)
                    SheepChildren += cattle.Children;

                else
                    GoatChildren += cattle.Children;
            }

            for (int i = 0; i < CowChildren; i++)
                LstCattle.Add(new Cow());
            
            for (int i = 0; i < SheepChildren; i++)
                LstCattle.Add(new Sheep());

            for (int i = 0; i < GoatChildren; i++)
                LstCattle.Add(new Goat());
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            ListCattle LstCattle = new ListCattle();
            LstCattle.GetInformation();
            LstCattle.MakeNoiseAll();
            LstCattle.PutInformation();

            LstCattle.GiveBirthAll();
            Console.WriteLine("\n----------------------------\n");
            Console.WriteLine("...CAC GIA SUC DA SINH CON...");
            LstCattle.PutInformation();

            Console.ReadKey();
        }
    }
}
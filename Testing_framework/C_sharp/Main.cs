///<sumamry>
/// Exampleusecase:
///</summary>

using System;
using Test_;

namespace Main
{
    class Program
    {
        static void Main(string[] args)
        {
            TEST.ASSERT(true, "");
            TEST.ASSERT(false, "");


            TEST.ASSERT_THROW<ArgumentNullException>(() => {
                string nullString = null;
                int length = nullString.Length;
            }, "");

            Console.ReadLine();
        }
    }
}

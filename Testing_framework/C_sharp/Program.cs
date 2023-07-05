using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Test_
{
    /// <summary>
    /// A class that provides ASSERTion methods for testing.
    /// </summary>
    class TEST
    {
        /// <summary>
        /// Gets the current timestamp as a string.
        /// </summary>
        /// <returns>The current timestamp as a string.</returns>
        private static string GetTimestamp()
        {
            return DateTime.Now.ToString("HH:mm:ss");
        }

        /// <summary>
        /// Prints an invocation message with the provided function name in yellow color.
        /// </summary>
        /// <param name="func">The name of the function being invoked.</param>
        private static void Invoke(string func)
        {
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("\n[TIME: {0}]  __{1}::INVOKED", GetTimestamp(), func);
            Console.ResetColor();
        }

        /// <summary>
        /// Prints a passing message with an optional function name in green color.
        /// </summary>
        /// <param name="funcName">An optional name of the function being tested.</param>
        private static void PRINT_PASS(string funcName = "")
        {
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("[TEST {0} PASSED]", funcName);
            Console.ResetColor();
        }

        /// <summary>
        /// Prints a failing message with an optional message and function name in red color.
        /// </summary>
        /// <param name="message">An optional message to include in the failure message.</param>
        /// <param name="funcName">An optional name of the function being tested.</param>
        private static void PRINT_FAIL(string message = "", string funcName = "")
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("[TEST {0} FAILED]", funcName);
            Console.ResetColor();
            if (!string.IsNullOrEmpty(message))
            {
                Console.WriteLine("  {0}", message);
            }
            
        }

        /// <summary>
        /// ASSERTs a condition and prints a pass message if the condition is true, or a fail message otherwise.
        /// </summary>
        /// <typeparam name="T">The type of the condition.</typeparam>
        /// <param name="condition">The condition to ASSERT.</param>
        /// <param name="message">An optional message to include in the fail message.</param>
        /// <param name="funcName">An optional name of the function being tested.</param>
        public static void ASSERT<T>(T condition, string message = "", string funcName = "")
        {
            Invoke(nameof(ASSERT));
            if (condition is bool && (bool)(object)condition)
            {
                PRINT_PASS(funcName);
            }
            else
            {
                PRINT_FAIL(message, funcName);
            }
        }

        /// <summary>
        /// ASSERTs that the expected value is equal to the actual value and prints a pass message if they are equal,
        /// or a fail message otherwise.
        /// </summary>
        /// <typeparam name="T">The type of the expected and actual values.</typeparam>
        /// <param name="expected">The expected value.</param>
        /// <param name="actual">The actual value.</param>
        /// <param name="message">An optional message to include in the fail message.</param>
        /// <param name="funcName">An optional name of the function being tested.</param>
        public static void ASSERT_EQUAL<T>(T expected, T actual, string message = "", string funcName = "")
        {
            Invoke(nameof(ASSERT_EQUAL));
            if (EqualityComparer<T>.Default.Equals(expected, actual))
            {
                PRINT_PASS(funcName);
            }
            else
            {
                PRINT_FAIL(message, funcName);
                Console.WriteLine("[expected]: {0} ->  [actual]: {1}", expected, actual);
            }
        }

        /// <summary>
        /// ASSERTs that the expected value is not equal to the actual value and prints a pass message if they are not equal, or a fail message otherwise.
        /// </summary>
        /// <typeparam name="T">The type of the expected and actual values.</typeparam>
        /// <param name="notExpected">The value that is not expected.</param>
        /// <param name="actual">The actual value.</param>
        /// <param name="message">An optional message to include in the fail message.</param>
        /// <param name="funcName">An optional name of the function being tested.</param>
        public static void ASSERT_NOT_EQUAL<T>(T notExpected, T actual, string message = "", string funcName = "")
        {
            Invoke(nameof(ASSERT_NOT_EQUAL));
            if (!EqualityComparer<T>.Default.Equals(notExpected, actual))
            {
                PRINT_PASS(funcName);
            }
            else
            {
                PRINT_FAIL(message, funcName);
                Console.WriteLine("[not expected]: {0} ->  [actual]: {1}", notExpected, actual);
            }
        }

        /// <summary>
        /// Asserts that a condition is true and prints a pass message if it is true, or a fail message otherwise.
        /// </summary>
        /// <param name="condition">The condition to assert.</param>
        /// <param name="message">An optional message to include in the fail message.</param>
        /// <param name="funcName">An optional name of the function being tested.</param>
        public static void ASSERT_TRUE(bool condition, string message = "", string funcName = "")
        {
            Invoke(nameof(ASSERT_TRUE));
            if (condition)
            {
                PRINT_PASS(funcName);
            }
            else
            {
                PRINT_FAIL(message, funcName);
            }
        }

        /// <summary>
        /// Asserts that a condition is false and prints a pass message if it is false, or a fail message otherwise.
        /// </summary>
        /// <param name="condition">The condition to assert.</param>
        /// <param name="message">An optional message to include in the fail message.</param>
        /// <param name="funcName">An optional name of the function being tested.</param>
        public static void ASSERT_FALSE(bool condition, string message = "", string funcName = "")
        {
            Invoke(nameof(ASSERT_FALSE));
            if (!condition)
            {
                PRINT_PASS(funcName);
            }
            else
            {
                PRINT_FAIL(message, funcName);
            }
        }

        /// <summary>
        /// Asserts that the specified statement throws an exception of type ExceptionType and prints a pass message if it does, or a fail message otherwise.
        /// </summary>
        /// <typeparam name="ExceptionType">The type of exception that is expected to be thrown.</typeparam>
        /// <param name="statement">The statement to execute.</param>
        /// <param name="message">An optional message to include in the fail message.</param>
        /// <param name="funcName">An optional name of the function being tested.</param>
        public static void ASSERT_THROW<ExceptionType>(Action statement, string message = "", string funcName = "") where ExceptionType : Exception
        {
            Invoke(nameof(ASSERT_THROW));
            try
            {
                statement();
                PRINT_FAIL(message, funcName);
            }
            catch (ExceptionType)
            {
                PRINT_PASS(funcName);
            }
            catch (Exception ex)
            {
                PRINT_FAIL(message, funcName);
                Console.WriteLine("[expected exception type]: {0}", typeof(ExceptionType).Name);
            }
        }

        /// <summary>
        /// Asserts that the specified statement does not throw an exception of type ExceptionType and prints
        /// a pass message if it does not throw, or a fail message otherwise.
        /// </summary>
        /// <typeparam name="ExceptionType">The type of exception that is not expected to be thrown.</typeparam>
        /// <param name="statement">The statement to execute.</param>
        /// <param name="message">An optional message to include in the fail message.</param>
        /// <param name="funcName">An optional name of the function being tested.</param>
        public static void ASSERT_NO_THROW<ExceptionType>(Action statement, string message = "", string funcName = "") where ExceptionType : Exception
        {
            Invoke(nameof(ASSERT_NO_THROW));
            try
            {
                statement();
                PRINT_PASS(funcName);
            }
            catch (ExceptionType)
            {
                PRINT_FAIL(message, funcName);
                Console.WriteLine("[unexpected exception type]: {0}", typeof(ExceptionType).Name);
            }
        }
    }
}

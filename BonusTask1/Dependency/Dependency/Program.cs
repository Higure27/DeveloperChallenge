using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;
using System.Text;
using System.Threading.Tasks;

namespace Dependency
{
    class Program
    {
        static void Main(string[] args)
        {
            string givenProjectString = Console.ReadLine();
            givenProjectString =Regex.Replace(givenProjectString, @"projects:", "");
            givenProjectString = givenProjectString.Replace(" ", "");
            List<string> givenProjectsList = givenProjectString.Split(',').ToList();

            string dependencyString = Console.ReadLine();
            MatchCollection matchList = Regex.Matches(dependencyString, @"\(([^)]*)\)");
            List<string> dependencyPairList = matchList.Cast<Match>().Select(match => match.Value).ToList();
            Dictionary<string, List<string>> allDependecies = new Dictionary<string, List<string>>();

            foreach(string pair in dependencyPairList)
            {
                string currentPair = pair.Replace(" ","");
                currentPair = currentPair.Replace(")", "");
                currentPair = currentPair.Replace("(", "");
                GetDependencyFromString(currentPair, allDependecies);
            }
        }

        private static void GetDependencyFromString(string currentPair, Dictionary<string, List<string>> allDependecies)
        {
            string[] dependeeDependent = currentPair.Split(',');
            string dependee = dependeeDependent[0];
            string dependent = dependeeDependent[1];

            if(!allDependecies.ContainsKey(dependent))
            {
                allDependecies.Add(dependent, new List<string>());
            }

            allDependecies[dependent].Add(dependee);
        }
    }
}

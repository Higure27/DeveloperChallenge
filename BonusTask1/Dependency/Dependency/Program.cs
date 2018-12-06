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
            //Get list of all projects
            string givenProjectString = Console.ReadLine();
            givenProjectString =Regex.Replace(givenProjectString, @"projects:", "");
            givenProjectString = givenProjectString.Replace(" ", "");
            List<string> givenProjectsList = givenProjectString.Split(',').ToList();

            //Get string of all dependencis 
            string dependencyString = Console.ReadLine();
            MatchCollection matchList = Regex.Matches(dependencyString, @"\(([^)]*)\)");
            List<string> dependencyPairList = matchList.Cast<Match>().Select(match => match.Value).ToList();
            //key: Dependent, value: list of dependees
            Dictionary<string, List<string>> allDependecies = new Dictionary<string, List<string>>();

            //Put dependencis into dictionary
            foreach(string pair in dependencyPairList)
            {
                string currentPair = pair.Replace(" ","");
                currentPair = currentPair.Replace(")", "");
                currentPair = currentPair.Replace("(", "");
                GetDependencyFromString(currentPair, allDependecies);
            }
        }

        /// <summary>
        /// Gets dependency ffrom the string and puts into dependencies dictionary. 
        /// </summary>
        /// <param name="currentPair"></param>
        /// <param name="allDependecies"></param>
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

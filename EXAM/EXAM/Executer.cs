using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;

namespace EXAM
{
    internal class Executer
    {
       
        private List<Plan> _plans;
        //private string pathToJSON = "user.json";

        public List<Plan> GetPlans(string path)
        {

            {
                _plans = new List<Plan>();
             
                using StreamReader sr = new StreamReader(path);
                {
                  while (!sr.EndOfStream)
                    {
                        string oneStr = sr.ReadLine();

                        if (oneStr != string.Empty)
                        {
                            Plan? plan = JsonSerializer.Deserialize<Plan>(oneStr);
                            if (plan != null) _plans.Add(plan);

                        }
                    }
                    sr.Close();

                }
                return _plans;

            }
        }
        
      public void Execude(List<Plan> plans)
        {

            if (plans.Count > 0)
            {

                for (int i = 0; i < plans.Count; i++)
                {
                    if (plans[i].Time < DateTime.Now)
                    {
                        
                        plans.Remove(plans[i]);
                        _plans = plans;
                    }
                    //  return;

                }
            }
            else
            {

                return;
            }
        }
        
    }
}

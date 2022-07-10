using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EXAM
{
    internal class Plan
    {

        public string Type { get; }
        public string Content { get; set; }

        public DateTime Time { get; set; }
        public Plan(string type, string content, DateTime time)
        {
            Type = type;
            Content = content;
            Time = time;
        }
        /*
        private string Type;
        private string Content;
        private DateTime Time;

      
            public Plan(string type, string content, DateTime time)
            {
                Type = type;
                Content = content;
                Time = time;
            }
        */
        /*
        public string GetType()
        {
            return Type;
        }
        public string GetContent()
        {
            return Content;
        }
        public DateTime GetTime()
        {
            return Time;
        }

        public void SetType(string type)
        {
            this.Type=type;
        }
        public void SetContent(string content)
        {
            this.Content = content;
        }
        public void SetTime(DateTime time)
        {
            this.Time = time;
        }
        */
    }
}

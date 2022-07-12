using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;

namespace EXAM
{
    internal class Executor  // Класс выполнятор

    {

        private List<Plan> _plans = new List<Plan>(); // Лист планов на сегодня


        public List<Plan> Init(string path)  // Инициализация планов (читаем JSON)
        {
            if (_plans.Count > 0)
            {
                _plans.Clear();
            }

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
        public List<Plan> GetPlans()
        {
            return _plans;
        }

        public void SetPlans(List<Plan> plans)
        {
            _plans = plans;
        }

        public void Execude(List<Plan> plans)   // функция выполнить
        {

            if (plans.Count > 0)
            {
                for (int i = 0; i < plans.Count; i++)
                {
                    if (plans[i].Time < DateTime.Now)  // Сравниваем текущие время с запланированным 
                    {
                        if (plans[i].Type == "Message")  // Смотрим тип выполняемой задачи
                        {
                            DialogResult result = MessageBox.Show(plans[i].Content, "Message", MessageBoxButtons.OK, MessageBoxIcon.Information);
                                                            //Если тип Message: Выводим MessageBox с сообщением
                            if (result == DialogResult.OK)
                            {
                                plans.Remove(plans[i]);  // удаляем из списка
                                SetPlans(plans);        // сохраняем
                                return;
                            }

                        }
                        else if (plans[i].Type == "Load")
                        {
                            DialogResult result = MessageBox.Show(Path.GetFileNameWithoutExtension(plans[i].Content), "Load", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                                                        //Если тип Load: Выводим MessageBox и спрашиваем загружать или нет
                            if (result == DialogResult.Yes) //если да
                            {
                                Process iStartProcess = new Process();              //Запускаем новый процесс
                                iStartProcess.StartInfo.FileName = @plans[i].Content;
                                iStartProcess.Start();
                                plans.Remove(plans[i]); // удаляем из списка
                                SetPlans(plans);        // сохраняем
                                return;
                            }
                            else                        //если нет просто удалям из планов
                            {
                                plans.Remove(plans[i]);     
                                SetPlans(plans);
                                return;
                            }

                        }

                    }

                }
            }
            else
            {

                return;
            }
        }

        public void ReWretiter(List<Plan> plans)  //функция перезаписи JSON
        {
            using StreamWriter sw = new StreamWriter("user.json");
            {
                foreach (var item in plans)
                {
                    sw.WriteLine(JsonSerializer.Serialize<Plan>(item));

                }
              
            }
        }

    }
}

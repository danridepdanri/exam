using System.Diagnostics;

namespace EXAM
{
    public partial class Form1 : Form
    {

        private Executor _executor = new Executor();
        private string pathToJSON = "user.json";

        public Form1()
        {
            InitializeComponent();

            _executor.Init(pathToJSON); // инициализируем выполнятор со списком планов

            /*  события по сворачиванию и разворачиванию в трее
             *
             */
            ExecuterIcon.Visible = false;
            this.ExecuterIcon.MouseDoubleClick += new MouseEventHandler(ExecuterIcon_MouseDoubleClick);
            this.Resize += new EventHandler(this.Form1_Resize);
            TimerEX.Tick += TimerEX_Tick;

            TimerEX.Start(); // запуск таймера

            listView_Plans.Items.Clear();           
            listView_Plans.View = View.Details;


            for (int i = 0; i < _executor.GetPlans().Count; i++)
            {

                if (_executor.GetPlans()[i].Time.Date == DateTime.Now.Date) // В ListView грузим только те что запланированы на сегодня
                {

                    ListViewItem item;
                    if (_executor.GetPlans()[i].Type == "Load")
                    {
                        item = new ListViewItem(_executor.GetPlans()[i].Type);
                        item.SubItems.Add(Path.GetFileNameWithoutExtension(_executor.GetPlans()[i].Content));
                        item.SubItems.Add(_executor.GetPlans()[i].Time.ToString());
                    }
                    else
                    {
                        item = new ListViewItem(_executor.GetPlans()[i].Type);
                        item.SubItems.Add(_executor.GetPlans()[i].Content);
                        item.SubItems.Add(_executor.GetPlans()[i].Time.ToString());
                    }

                    listView_Plans.Items.Add(item);
                }
            }
        }
        // сворачивание в трей
        private void Form1_Resize(object sender, EventArgs e)
        {

            if (WindowState == FormWindowState.Minimized)
            {
                Hide();
                ExecuterIcon.Visible = true;
                ExecuterIcon.BalloonTipTitle = "Программа была спрятана";
                ExecuterIcon.BalloonTipText = "Обратите внимание что программа была спрятана в трей и продолжит свою работу.";
                ExecuterIcon.ShowBalloonTip(5000); // Параметром указываем количество миллисекунд, которое будет показываться подсказка
            }
        }
        //разворачиваем из трея
        private void ExecuterIcon_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            this.Show();
            ExecuterIcon.Visible = false;
            WindowState = FormWindowState.Normal;

        }

        // режим работы таймера
        private void TimerEX_Tick(object sender, EventArgs e)
        {
            if (WindowState == FormWindowState.Minimized)
            {
                this.Show();
                ExecuterIcon.Visible = false;
                WindowState = FormWindowState.Normal;
            }
            TimerEX.Interval = 30000;
            _executor.Execude(_executor.GetPlans());
        }
        //при закрытии программы перезаписываем JSON
        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            _executor.ReWretiter(_executor.GetPlans());
        }
        // тут еще работаю
        private void btnADD_Click(object sender, EventArgs e)
        {
            addForm addForm = new addForm(this);
            addForm.Show();
        }
    }


}

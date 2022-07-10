namespace EXAM
{
    public partial class Form1 : Form
    {
   
        private Executer Executer = new Executer();
        private string pathToJSON = "user.json";
       
        public Form1()
        {
            InitializeComponent();

            ExecuterIcon.Visible = false;
            this.ExecuterIcon.MouseDoubleClick += new MouseEventHandler(ExecuterIcon_MouseDoubleClick);
            this.Resize += new EventHandler(this.Form1_Resize);
            TimerEX.Tick += TimerEX_Tick;

            TimerEX.Start();

            listView_Plans.Items.Clear();
            listView_Plans.View = View.Details;


            for (int i = 0; i < Executer.GetPlans(pathToJSON).Count; i++)
            {
                ListViewItem item = new ListViewItem(Executer.GetPlans(pathToJSON)[i].Content);
                item.SubItems.Add(Executer.GetPlans(pathToJSON)[i].Time.ToString());

                listView_Plans.Items.Add(item);

            }

            //listBox_Plans.Items.Clear();
            //for (int i = 0; i < Executer.GetPlans(pathToJSON).Count; i++)
            //{
            //    listBox_Plans.Items.Add(Executer.GetPlans(pathToJSON)[i].Content +"\t" + Executer.GetPlans(pathToJSON)[i].Time.ToShortTimeString());

            //}


        }

        private void Execude(List<Plan> plans)
        {

            if (plans.Count > 0)
            {

                for (int i = 0; i < plans.Count; i++)
                {
                    if (plans[i].Time < DateTime.Now)
                    {
                        label2.Text = plans[i].Content;
                        label3.Text = plans[i].Time.ToShortDateString();
                        plans.Remove(plans[i]);
                        // plans = plans;
                    }
                    //  return;

                }
            }
            else
            {

                return;
            }
        }

        private void TimerEX_Tick1(object? sender, EventArgs e)
        {
            throw new NotImplementedException();
        }

        private void Form1_Resize(object sender, EventArgs e)
        {

            if (WindowState == FormWindowState.Minimized)
            {
                Hide();
                ExecuterIcon.Visible = true;
                ExecuterIcon.BalloonTipTitle = "ѕрограмма была спр€тана";
                ExecuterIcon.BalloonTipText = "ќбратите внимание что программа была спр€тана в трей и продолжит свою работу.";
                ExecuterIcon.ShowBalloonTip(5000); // ѕараметром указываем количество миллисекунд, которое будет показыватьс€ подсказка
            }
        }

        private void ExecuterIcon_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            this.Show();
            ExecuterIcon.Visible=false;
            WindowState = FormWindowState.Normal;

        }

        private void TimerEX_Tick(object sender, EventArgs e)
        {
            Execude(Executer.GetPlans(pathToJSON));
        }

       
    }

    
}

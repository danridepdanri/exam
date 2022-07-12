namespace EXAM
{
    partial class addForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.dateTimePicker_Date = new System.Windows.Forms.DateTimePicker();
            this.comBox_selectType = new System.Windows.Forms.ComboBox();
            this.dateTimePicker_Time = new System.Windows.Forms.DateTimePicker();
            this.SuspendLayout();
            // 
            // dateTimePicker_Date
            // 
            this.dateTimePicker_Date.Location = new System.Drawing.Point(12, 60);
            this.dateTimePicker_Date.Name = "dateTimePicker_Date";
            this.dateTimePicker_Date.Size = new System.Drawing.Size(246, 23);
            this.dateTimePicker_Date.TabIndex = 0;
            // 
            // comBox_selectType
            // 
            this.comBox_selectType.FormattingEnabled = true;
            this.comBox_selectType.Location = new System.Drawing.Point(12, 12);
            this.comBox_selectType.Name = "comBox_selectType";
            this.comBox_selectType.Size = new System.Drawing.Size(246, 23);
            this.comBox_selectType.TabIndex = 1;
            // 
            // dateTimePicker_Time
            // 
            this.dateTimePicker_Time.Format = System.Windows.Forms.DateTimePickerFormat.Time;
            this.dateTimePicker_Time.Location = new System.Drawing.Point(12, 110);
            this.dateTimePicker_Time.Name = "dateTimePicker_Time";
            this.dateTimePicker_Time.Size = new System.Drawing.Size(246, 23);
            this.dateTimePicker_Time.TabIndex = 2;
            // 
            // addForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(270, 173);
            this.Controls.Add(this.dateTimePicker_Time);
            this.Controls.Add(this.comBox_selectType);
            this.Controls.Add(this.dateTimePicker_Date);
            this.Name = "addForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Add plan";
            this.ResumeLayout(false);

        }

        #endregion

        private DateTimePicker dateTimePicker_Date;
        private ComboBox comBox_selectType;
        private DateTimePicker dateTimePicker_Time;
    }
}
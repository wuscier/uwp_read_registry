using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace HWAssistantWPF
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        [DllImport("HWASDKAgent.dll", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        internal static extern bool IsRegistryValueExist(UInt32 root, string subKey, string valueName);

        private void btn_Click(object sender, RoutedEventArgs e)
        {
            bool result = IsRegistryValueExist(0x80000002, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", "SecurityHealth");
        }
    }
}

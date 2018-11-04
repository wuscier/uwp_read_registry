using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x804 上介绍了“空白页”项模板

namespace HWAssistantLight
{
    /// <summary>
    /// 可用于自身或导航至 Frame 内部的空白页。
    /// </summary>
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            this.InitializeComponent();
        }


        [DllImport("HWASDKAgent.dll",ExactSpelling =true,CallingConvention =CallingConvention.Cdecl,CharSet = CharSet.Ansi)]
        internal static extern bool IsRegistryValueExist(UInt32 root, string subKey, string valueName);

        private void btn_Click(object sender, RoutedEventArgs e)
        {
            bool result = IsRegistryValueExist(0x80000002, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", "SecurityHealth");
            btn.Content = result.ToString();
        }
    }
}

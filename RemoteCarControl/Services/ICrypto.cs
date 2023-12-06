using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RemoteCarControl.Services
{
    public interface ICrypto
    {
        public string encrypt(string val);
        public string decrypt(string val);
    }
}

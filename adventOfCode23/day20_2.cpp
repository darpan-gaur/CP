#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Module{
    public:
        string name;
        string type;
        vector<string> outputs;
        map<string, string> memory;
        //Empty constructor
        Module() {
            this->name = "";
            this->type = "";
            this->outputs = {};
        } 
        Module(string name, string type, vector<string> outputs) {
            this->name = name;
            this->type = type;
            this->outputs = outputs;
            if (type=="%") {
                this->memory["state"] = "off";
            }
            else {
                this->memory = {};
            }
        }
};

int main() {
    vector<string> broadcast_outputs;
    map<string, Module> modules;

    string line;
    while (getline(cin, line)) {
        // get the left side of the arrow
        string left = line.substr(0, line.find("->")-1);
        // get the right side of the arrow
        string right = line.substr(line.find(" -> ")+3);
        // split right into a vector of outputs
        vector<string> outputs;
        string output;
        stringstream ss(right);
        while (getline(ss, output, ',')) {
            // push back from index 1
            outputs.push_back(output.substr(1));
        }
        // for (auto i : outputs) {
        //     cout << i << ":";
        // }cout << endl;
        if (left == "broadcaster") {
            broadcast_outputs = outputs;            
        }
        else {
            string typ = left.substr(0, 1);
            string name = left.substr(1);
            modules[name] = Module(name, typ, outputs);
        }
    }
    // for type '&' set memory of their outputs which are in modules to low
    for (auto i : modules) {
        for (auto j : i.second.outputs) {
            if (modules.find(j) != modules.end() && modules[j].type == "&") {
                modules[j].memory[i.first] = "low";
            }
        }
    }

    // Assumption only one parent of rx
    // find the origin of "rx" signal
    string prt;
    for (auto i :modules) {
        for (auto j: i.second.outputs) {
            if (j == "rx") {
                prt = i.first;
            }
        }
    }
    cout << prt << endl;

    // print modules
    // for (auto i : modules) {
    //     cout << i.first << ":";
    //     for (auto j : i.second.outputs) {
    //         cout << j << ",";
    //     }
    //     cout << "mem-";
    //     for (auto j : i.second.memory) {
    //         cout << j.first << ":" << j.second << ",";
    //     }
    //     cout << endl;
    // }

    map<string, ll> seen;
    for (auto i : modules) {
        for (auto j : i.second.outputs) {
            if (j == prt) {
                seen[i.first] = 0;
            }
        }
    }
    map<string, ll> cycLen;

    ll btn_press = 0;
    while (true) {
        btn_press++;
        queue<vector<string>> q;
        for (auto j : broadcast_outputs) {
            q.push({"broadcaster", j, "low"});
        }
        while (!q.empty()) {
            string source = q.front()[0];
            string dest = q.front()[1];
            string pulse = q.front()[2];
            q.pop();

            // cout << source << "->" << dest << ":" << pulse << endl;
            if (modules.find(dest) == modules.end()) continue;

            auto& module = modules[dest];
            
            if (module.name == prt && pulse == "high") {
                seen[source]+=1;

                if (cycLen.find(source) == cycLen.end()) {
                    cycLen[source] = btn_press;
                }
                
                // check if all seen values are greater than 0, then break
                bool allSeen = true;
                for (auto i : seen) {
                    if (i.second == 0) {
                        allSeen = false;
                        break;
                    }
                }
                if (allSeen) {
                    // Assumption prt parent is & type
                    ll lcm = 1;
                    for (auto i : cycLen) {
                        lcm = lcm*i.second/__gcd(lcm, i.second);
                    }
                    cout << lcm << endl;
                    return 0;
                }
            }
            
            if (module.type == "%") {
                if (pulse == "low") {
                    module.memory["state"] = (module.memory["state"] == "off") ? "on" : "off";
                    string newPulse = (module.memory["state"] == "off") ? "low" : "high";
                    for (auto i : module.outputs) {
                        q.push({module.name, i, newPulse});
                    }
                }
            }
            else {
                module.memory[source] = pulse;
                string newPulse = "low";
                for (auto i : module.memory) {
                    if (i.second == "low") {
                        newPulse = "high";
                        break;
                    }
                }
                for (auto i : module.outputs) {
                    q.push({module.name, i, newPulse});
                }
            }
        }
        // break;
    }

    return 0;
}
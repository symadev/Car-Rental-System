#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class File
{
private:
    string filename;
    fstream file;

public:
    File(string filename) {
        this->filename = filename;
    }

    void setRecord(string record) {
        this->file.open(this->filename, ios_base::app);
        this->file << record;
        this->file << "\n";
        this->file.close();
    }

    vector< vector<string> > getRecords() {
        string line;
        string cell;
        vector< vector<string> > matrix;

        this->file.
        aqswaopen(this->filename);
        
        while(getline(this->file, line)) {

            stringstream lineStream(line);
            vector<string> parsedRow;

            while(getline(lineStream, cell, ',')) {
                parsedRow.push_back(cell);
            }

            matrix.push_back(parsedRow);
        }

        this->file.close();

        return matrix;
    }
};
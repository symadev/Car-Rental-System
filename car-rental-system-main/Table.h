using namespace std;

class Table
{
private:
    int *columnWidth;
    string *heading;
    int columnSize;
    vector< vector<string> > matrix;

public:
    void setColumnWidth(int *columnWidth) {
        this->columnWidth = columnWidth;
    }

    void setHeading(string *heading) {
        this->heading = heading;
    }

    void setColumnSize(int columnSize) {
        this->columnSize = columnSize;
    }

    void setData(vector< vector<string> > matrix) {
       this->matrix = matrix;
    }

    void show() {
        int i,j,k,count;

        for (i = 0; i < this->columnSize; i++) {
            count = this->columnWidth[i] - this->heading[i].length();
            cout << this->heading[i];

            if (count > 0) {
                for (j = 0; j < count; j++) {
                    cout << " ";
                }
            }
        }

        cout << "\n";

        for (i = 0; i < this->matrix.size(); i++) {

            for (j = 0; j < this->matrix[i].size(); j++){
                cout << this->matrix[i][j];

                count = this->columnWidth[j] - this->matrix[i][j].size();
                if (count > 0) {
                    for (k = 0; k < count; k++) {
                        cout << " ";
                    }
                }
            }

            cout << "\n";
        }
    }
};
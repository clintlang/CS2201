// generate a random dice file for the boggle pgm
// ROTH

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <random>

const int SIZE(4);
const int NUM_DICE(SIZE*SIZE);
const int NUM_FACES(6);
const std::string IN_FILE_NAME("boggle-dice.txt");
const std::string OUT_FILE_NAME("boggle-in.txt");

void openFiles(std::ifstream &fin, std::ofstream &fout);

void readDice(std::ifstream &fin, char dice[NUM_DICE][NUM_FACES], bool used[NUM_DICE]);

void generateData(std::ofstream &fout, char dice[NUM_DICE][NUM_FACES], bool used[NUM_DICE]);


int main() {

    std::cout << "\nThis program will generate a random boggle-in.txt file." << std::endl;

    std::ofstream fout;
    std::ifstream fin;

    char dice[NUM_DICE][NUM_FACES];
    bool used[NUM_DICE];

    openFiles(fin,fout);

    readDice(fin, dice, used);

    generateData(fout, dice, used);

    fin.close();
    fout.close();
    std::cout << std::endl;

    std::cout << "Press enter to end program.";
    std::cin.get();
    std::cin.get();

    return 0;
}


void openFiles(std::ifstream &fin, std::ofstream &fout) {
    fout.open(OUT_FILE_NAME);
    if (fout.fail()) {
        std::string msg("Unable to open " + OUT_FILE_NAME + " for writing.");
        std::cout << msg << std::endl;
        throw std::runtime_error(msg);
    }
    fin.open(IN_FILE_NAME);
    if (fin.fail()) {
        std::string msg("Unable to open " + IN_FILE_NAME + " for reading.");
        std::cout << msg << std::endl;
        throw std::runtime_error(msg);
    }
}

void readDice(std::ifstream &fin, char dice[NUM_DICE][NUM_FACES], bool used[NUM_DICE]) {
    for (int m = 0; m < NUM_DICE; m++) {
        used[m] = false;
        for (int n = 0; n < NUM_FACES; n++) {
            fin >> dice[m][n];
        }
    }
}

void generateData(std::ofstream &fout, char dice[NUM_DICE][NUM_FACES], bool used[NUM_DICE]) {

    std::cout << "Enter a random integer (entering the same integer will" << std::endl;
    std::cout << "generate the same boggle-in.txt file): ";
    int tmp;
    std::cin >> tmp;

    unsigned seed = (unsigned) tmp;
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> dieDistribution(0, NUM_DICE-1);
    std::uniform_int_distribution<int> faceDistribution(0, NUM_FACES-1);

    std::cout << "\nThe " << OUT_FILE_NAME << " file now contains:\n " << std::endl;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            // pick a random, unused die
            int die = dieDistribution(generator);
            while (used[die]) die = dieDistribution(generator);
            used[die] = true;

            // pick a random face of the die
            int face = faceDistribution(generator);

//            std::cout << "DEBUG:: using die #" << die << " and face " << face << std::endl;

            char ch = dice[die][face];
            fout << ch;
            std::cout << ch;
        }
        fout << std::endl;
        std::cout << std::endl;
    }

}
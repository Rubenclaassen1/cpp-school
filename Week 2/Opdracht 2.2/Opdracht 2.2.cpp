// Opdracht 2.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Opdracht2.2.h";




void findGenes(std::string& genome) {
    //checks if the string has content
    if (genome.length() > 0) {
        //finds the start of a genome
        size_t startpos = genome.find("ATG");
        if (startpos != std::string::npos) {
            //removes the part of the string before the start of a genome
            std::string possible_gene = genome.substr(startpos + 3, genome.length() - (startpos + 3));

            //checks if the gene has an end
            size_t geneEnd = findEnd(possible_gene);

            //sets up recursion to find multiple genes in the string
            if (geneEnd == NULL) {
                findGenes(possible_gene);
            }
            else {
                std::string nextCheck = possible_gene.substr(geneEnd+3, possible_gene.length() - (geneEnd+3));
                findGenes(nextCheck);
            }


        }


    }


}

size_t findEnd(std::string& possible_gene) {

    std::string substrings[] = { "TAG", "TGA", "TTA" };

    size_t found = std::string::npos;

    //checks if any of the substrings is in the string
    for (std::string substr : substrings) {
        found = possible_gene.find(substr);
        if (found != std::string::npos) {
            std::string gene = possible_gene.substr(0, found);
            //checks if the gene consists of triplets
            if (gene.length() % 3 == 0) {
                std::cout << "Gene: " << gene << std::endl;
                return found;
                break;
            }
            //sets found back on npos when its not a gene
            else {
                found = std::string::npos;
            }

        }
    }

    if (found == std::string::npos) {
        return NULL;
    }

}




int main()
{
    std::string genome;
    std::cout << "Enter the genome sequence: ";
    std::cin >> genome;

    findGenes(genome);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

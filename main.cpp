#include <iostream>
#include <libxml/parser.h>
#include <libxml/tree.h>

using namespace std;

void printTitles(xmlNode *node) {
    for (xmlNode *cur = node; cur != nullptr; cur = cur->next) {
        if (cur->type == XML_ELEMENT_NODE) {
            if (xmlStrEqual(cur->name, BAD_CAST "title")) {
                xmlChar *content = xmlNodeGetContent(cur);
                if (content) {
                    cout << (const char*)content << endl;
                    xmlFree(content);
                }
            }
        }
        printTitles(cur->children);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <xmlfile>" << endl;
        return 1;
    }

    xmlDoc *doc = xmlReadFile(argv[1], nullptr, 0);
    if (doc == nullptr) {
        cerr << "Failed to parse XML file." << endl;
        return 1;
    }

    xmlNode *root = xmlDocGetRootElement(doc);
    if (root == nullptr) {
        cerr << "Empty XML document." << endl;
        xmlFreeDoc(doc);
        return 1;
    }

    printTitles(root);

    xmlFreeDoc(doc);
    xmlCleanupParser();

    
    return 0;
}

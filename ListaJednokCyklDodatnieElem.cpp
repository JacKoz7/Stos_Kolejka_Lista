struct Node {
    int data;
    Node* next;
};

int count_positive_numbers(Node* current) {
    if (current == nullptr) {
        return 0;
    }

    int count = 0;
    Node* start = current;

    do {
        if (current->data > 0) {
            count++;
        }
        current = current->next;
    } while (current != start);

    return count;
}

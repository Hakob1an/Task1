from docManager import DocumentManager

class UI:
    def __init__(self):
        self.manager = DocumentManager()
    
    def run(self):
        while True:
            self.display_menu()
            choice = input("Enter choice: ")
            if choice == '6':
                print("Exiting...")
                break
            self.process_choice(choice)
    
    def display_menu(self):
        print("\n-------------------")
        print("\nOptions:\n")
        print("1. Create Document")
        print("2. Edit Document")
        print("3. View Document")
        print("4. Show Documents")
        print("5. Delete Document")
        print("6. Exit")
        print("-------------------")
    
    def process_choice(self, choice):
        if choice == '1':
            self.create_document()
        elif choice == '2':
            self.edit_document()
        elif choice == '3':
            self.view_document()
        elif choice == '4':
            self.show_documents()
        elif choice == '5':
            self.delete_document()
        else:
            print("Invalid choice, please try again.")
    
    def create_document(self):
        file_name = input("Enter file name: ")
        self.manager.create(file_name)
    
    def edit_document(self):
        file_name = input("Enter file name to edit: ")
        append = input("Append to the document? (yes/no): ").lower() == 'yes'
        self.manager.edit(file_name, append)
    
    def view_document(self):
        file_name = input("Enter file name to view: ")
        self.manager.view(file_name)
    
    def show_documents(self):
        self.manager.show()
    
    def delete_document(self):
        file_name = input("Enter file name to delete: ")
        self.manager.delete_document(file_name)


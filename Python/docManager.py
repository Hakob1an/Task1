import os

class DocumentManager:
    def create(self, file_name):
        """Create a new document."""
        with open(file_name, 'w') as file:
            print(f"Document {file_name} created successfully.")
    
    def edit(self, file_name, append=False):
        """Edit an existing document."""
        mode = 'a' if append else 'w'
        with open(file_name, mode) as file:
            print("Enter the contents (Enter '.' on a line by itself to stop):")
            while True:
                content = input()
                if content == ".":
                    break
                file.write(content + '\n')
        print(f"Content added to {file_name}")
    
    def view(self, file_name):
        """View the contents of a document."""
        try:
            with open(file_name, 'r') as file:
                print("File contents:")
                print(file.read())
        except FileNotFoundError:
            print(f"Error opening the file: {file_name}")
    
    def delete_document(self, file_name):
        """Delete a document."""
        if os.path.exists(file_name):
            os.remove(file_name)
            print(f"Document {file_name} deleted successfully.")
        else:
            print(f"File does not exist: {file_name}")
    
    def show(self):
        """Show all documents in the current directory."""
        print("-------------------\n")
        print("All documents:")
        files = [f for f in os.listdir('.') if os.path.isfile(f)]
        for f in files:
            print(f)
        print("-------------------")


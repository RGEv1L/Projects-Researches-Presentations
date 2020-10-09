#Program Name: Background removal for enchanced text reading via Image Thresholding.
#Date Created: 30-12-19
#Requirements: a) Python 3+ b) "os" module c) "glob" module d) "opencv-python" module e) "numpy" module


import os   #Basic OS Directory Operations
import glob #Pattern Based Directory Searches
import cv2  #To open/print image objects
import numpy as np  # For Matrix Manipulation





def main():
    input_folder = f'{os.getcwd()}/I/'  #Images to be converted

    try:
        input_folder = os.mkdir(input_folder)

    except OSError:
        print("Creation of the directory failed")

    else:
        print("Successfully created the directory")

    output_folder = f'{os.getcwd()}/O/' #Transformed Images

    try:
        output_folder = os.mkdir(output_folder)

    except OSError:
        print("Creation of the directory failed")
        # sys.exit()
    else:
        print("Successfully created the directory")

    # Fetching all images to be parsed
    dataset = glob.glob(f'{input_folder}*.bmp')
    print(dataset)

    #Traversing the Images
    for i in range(len(dataset)):
        img = cv2.imread(f'{dataset[i]}')

        #Creating a new image object.
        width, height,_ = img.shape
        new_img = np.zeros(shape=(width, height))

        o = 0   #Control variable
        while o == 0:

            #Getting the Thresholding Limit from user
            k = int(input("Enter the Thresholding Limit\n>>"))
            a=0
            b=0
            #Matrix Manipulation
            for x in img:
                for y in x:
                    new_img[a][b] = np.multiply(y[0],0.3) + np.multiply(y[1],0.5) + np.multiply(y[2],0.2)
                    b= b+1
                b = 0
                a= a+1



            #Printing New Image
            cv2.namedWindow('image', cv2.WINDOW_NORMAL)  # To open normal sized window
            cv2.imshow('image', new_img)
            cv2.waitKey(0)  # 0 is passed so that it could wait indefinitly to quit.
            cv2.destroyAllWindows()

            # Option for user to either redo calculation for this image or write this image.
            choice = int(input("Satisfied?\n1.Yes\n2.No\n>>"))
            if (choice == 1):
                # Dumping Image to Output Folder
                cv2.imwrite(f'{output_folder}{i}.bmp', new_img)
                o = 1   #Breaking while loop for this iteration




main()  #Main Function Call

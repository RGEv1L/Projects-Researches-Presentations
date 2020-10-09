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
    print(dataset,"\n")

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

            #Matrix Manipulation
            for x in range(width):
                for y in range(height):
                    #Getting RGB values
                    r = img[x][y][0]
                    g = img[x][y][1]
                    b = img[x][y][2]
                    #Grey-Scale Calculation
                    grey_scale = (r * 0.3) + (g * 0.5) + (b * 0.2)

                    #Image Thresholding
                    if ( grey_scale > k):
                        new_img[x][y] = 255 #Converting all light pixels to 255
                    else:
                        new_img[x][y] = 0   #Converting all dark pixels eg, black text, to 0



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

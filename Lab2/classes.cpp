// program to calculate and display area of a square, cube, rectangle, cuboid
# include <cstdio>
# include <cstdlib>

class area 
{
    private:
        float length, breadth, height;
    public:
        area() {
            length=1;breadth=1;height=1;
        };

        void set_length(float temp)
        {
            length = temp;
        }
        void set_breadth(float temp)
        {
            breadth = temp;
        }
        void set_height(float temp)
        {
            height = temp;
        }

        float square_area()
        {
            return (length*length);
        }
        float rectangle_area()
        {
            return (length*breadth);
        }
        float cube_area()
        {
            return (6*length*length);
        }
        float cuboid_area()
        {
            return (2*((length*breadth)+(breadth*height)+(height*length)));
        }
};

int main()
{
    area obj;
    int choice;
    float temp;
    while (1)
    {
        printf("\nFind area of:\n1. Square\n2. Cube\n3. Rectangle\n4. Cuboid\n5. Exit\n");
        printf("\nEnter menu number of operation you want to perform: ");
        scanf("%d", &choice);
        while (choice < 1 || choice >5)
        {
            printf("Error. Enter a valid menu number: ");
            scanf("%d", &choice);
        }
        switch (choice)
        {
            case 1:
            {    
                printf("Enter side: ");
                scanf("%f", &temp);
                while (temp<=0)
                {
                    printf("Error. Enter a positive value: ");
                    scanf("%f", &temp);
                }
                obj.set_length(temp);
                printf("Area is %f\n", obj.square_area());
                break;
            }
            case 2:
            {    
                printf("Enter side: ");
                scanf("%f", &temp);
                while (temp<=0)
                {
                    printf("Error. Enter a positive value: ");
                    scanf("%f", &temp);
                }
                obj.set_length(temp);
                printf("Area is %f\n", obj.cube_area());
                break;
            }
            case 3:
            {    
                printf("Enter length: ");
                scanf("%f", &temp);
                while (temp<=0)
                {
                    printf("Error. Enter a positive value: ");
                    scanf("%f", &temp);
                }
                obj.set_length(temp);
                printf("Enter breadth: ");
                scanf("%f", &temp);
                while (temp<=0)
                {
                    printf("Error. Enter a positive value: ");
                    scanf("%f", &temp);
                }
                obj.set_breadth(temp);
                printf("Area is %f\n", obj.rectangle_area());
                break;
            }
            case 4:
            {    
                printf("Enter length: ");
                scanf("%f", &temp);
                while (temp<=0)
                {
                    printf("Error. Enter a positive value: ");
                    scanf("%f", &temp);
                }
                obj.set_length(temp);
                printf("Enter breadth: ");
                scanf("%f", &temp);
                while (temp<=0)
                {
                    printf("Error. Enter a positive value: ");
                    scanf("%f", &temp);
                }
                obj.set_breadth(temp);
                printf("Enter height: ");
                scanf("%f", &temp);
                while (temp<=0)
                {
                    printf("Error. Enter a positive value: ");
                    scanf("%f", &temp);
                }
                obj.set_height(temp);
                printf("Area is %f\n", obj.cuboid_area());
                break;
            }
            case 5:
            {
                exit(0);
            }
            default:
                break;
        }
    }
}
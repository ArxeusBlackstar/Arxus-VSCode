reader = read(acceptor, rbuff1, sizeof(rbuff1));
    if (reader < 0)
    {
        printf("\n Read Error \n");
    }
    else
    {
        rbuff1[reader] = '\0';
        printf("\n Server: Client says : %s \n", rbuff1);
    }
    if (strcmp(rbuff1, "fackof") == 0)
    {
        exit(1);
    }

    strcat(loaf1, rbuff1);
    strcat(loaf1, "*> muthput");
    printf("\n");

    int p = system(loaf1);
    printf("%d\n", p);
    if (p == 0)
    {
        printf("\n Server says :- Valid Shit \n");
    }
    else
    {
        printf("\n Server says : File not present \n");
    }

    FILE *fp;
    fp = fopen("muthput", "r");

    if (fp == NULL)
    {
        printf("Cannot open file");
        exit(1);
    }

    int i = 0;

    while (fgets(line1, sizeof(line1), fp) != NULL)
    {
        strcat(wbuff1, line1);
        i++;
    }

    printf("%d", i);

    fclose(fp);
    system("rm muthput");

    writer = write(acceptor, wbuff1, sizeof(wbuff1));
    if (writer < 0)
    {
        printf("\n Write Error \n");
    }
    else
    {
        printf("\n Sent \n");
    }
void show_help();
int main(object me,string arg)
{
    int num;
    float val;
    if(!arg)
    {
        show_help();
        return 1;
    }
    if(sscanf(arg,"exp %d",num)==1 && num>0)
    {
        val = num/79.37;
        val=val*val*val;
        val=pow(val,0.5);
        printf("%d���������辭�鼶��Ϊ��%d\n",num,to_int(val));
    }
    else if(sscanf(arg,"skill %d",num)==1 && num>0)
    {
        val = pow(num*num,0.333333)*79.37;
        printf("%d����������ѧ�ļ��ܼ���Ϊ��%d\n",num,to_int(val));
    }
    else
    {
        show_help();
        return 1;
    }
    return 1;
}

void show_help()
{
    write("ʹ�÷�����\n");
    write("���㼼������ľ���ȼ���jisuan exp <���ܼ���>\n");
    write("���㾭��ȼ���ѧ�ļ��ܣ�jisuan skill <���鼶��>\n");
}

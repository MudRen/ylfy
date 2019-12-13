inherit F_CLEAN_UP;
int help();
int get_biaoshi(string biaoshi, object ob, object me,string sx,int n);

int main(object me, string arg)
{
        object ob;
        string sx;
        int n,sxd;
        
        if(!arg || sscanf(arg,"%s %d",sx,n)!=2)
        {
            help();
            return 1;
        }

        if( me != this_player(1) )
                return 0;
        
        ob = me->query_temp("link_ob");
        
        if( !ob )
                return 0;
        
        while( ob && ob->is_character() )
                ob = ob->query_temp("link_ob");
        
        sxd = me->query("xyzx_sys/shuxingdian",1);
        if(n<=0)
                return notify_fail(HIY"������������㡣\n"NOR);
        if(n>sxd)
                return notify_fail(HIY"������Ե㲻��"+n+"�㣬�޷����мӵ㡣\n"NOR);
        
        if(sx != "jz" && sx != "mj" && sx != "fy" && sx != "lx")
        {
            return notify_fail(HIY"���Ա�����jz,mj,fy,lx�е�һ��\n"NOR);
        }
        write(HIY"Ϊ�˰�ȫ���Ҫ����֤��ݱ�ʶ,�����������ݱ�ʶ��"NOR);
        input_to("get_biaoshi", 1,ob,me,sx,n);
        return 1;
}

int get_biaoshi(string biaoshi, object ob, object me,string sx,int n)
{
        string old_biaoshi;
        
        old_biaoshi = ob->query("biaoshiold");

        write("\n");
        
        if( crypt(biaoshi, old_biaoshi) != old_biaoshi )
        {
                write(HIR"��ݱ�ʶ��֤ʧ�ܣ�\n"NOR);
                return 0;
        }
        
        switch (sx)
        {
            case "jz":
                printf(HIG"��ϲ�㣡��ľ�׼������%s�㡣\n"NOR,chinese_number(n));
                me->add("xyzx_sys/jingzhun",n);
                me->add("xyzx_sys/shuxingdian",-n);
                break;
            case "mj":
                printf(HIW"��ϲ�㣡�������������%s�㡣\n"NOR,chinese_number(n));
                me->add("xyzx_sys/minjie",n);
                me->add("xyzx_sys/shuxingdian",-n);
                break;
            case "fy":
                printf(HIC"��ϲ�㣡��ķ�Ӧ������%s�㡣\n"NOR,chinese_number(n));
                me->add("xyzx_sys/fanying",n);
                me->add("xyzx_sys/shuxingdian",-n);
                break;
            case "lx":
                printf(HIC"��ϲ�㣡�������������%s�㡣\n"NOR,chinese_number(n));
                me->add("xyzx_sys/lingxing",n);
                me->add("xyzx_sys/shuxingdian",-n);
                break;
        }
        return 1;
}

int help()
{
        write(@TEXT
ָ���ʽ��jiadian <����> <����>
������jz��mj��fy��lx�е�һ�֡�
���ָ�������������Ե���䵽 [��׼�����ݡ���Ӧ������] ���������ϡ�
[jz]����׼��Ӱ�칥�������ʣ���ֵԽ�߻��ж��ֵļ���Խ��
[mj]�����ݣ�Ӱ�������ʣ���ֵԽ��Խ�����ױ����ֻ��У�
[fy]����Ӧ��Ӱ��񵲼��ʣ���Ч�ظ񵲿����������ִ󲿷��˺���
[lx]�����ԣ�Ӱ��Լ��ܾ��еĶ�Ϥ�������ֵԽ�߼��ܾ���ʩ�õĳɹ������Խ��
TEXT
        );
        return 1;
}

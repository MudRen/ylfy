// halt.c by.suimeng

int main(object me, string arg)
{

        if (me->is_fighting()) {
                me->remove_all_enemy();
                message_vision("$N�������һԾ������սȦ�����ˡ�\n", me); 
        }
        else if (!me->is_busy()) 
                return notify_fail("�����ڲ�æ��\n");
        else if ((int)me->query_temp("pending/exercise") != 0) {
                message_vision("$N���������е�����ǿ��ѹ�ص��վ��������\n", me);
                me->interrupt_me();
        }
        else if ((int)me->query_temp("pending/respirate") != 0){
                message_vision("$N��������̨�����е�����֮�������³�������վ��������\n", me);
                me->interrupt_me();
        }
        if (me->query("doing"))
        {
                write(BLINK HIR"�����ڱչ�,���halt�Ļ��������");
                write(BLINK HIR"һ���Ǳ��,��ȷ��Ҫ����չ�״̬");
                write(BLINK HIR"��?(y/n)\n");
                input_to("closed",me);
                return 1;
        }

        me->interrupt_me();


        return 1;
}

int closed(string str,object me)
{
        str=lower_case(str); //����Сд����

        if(str=="y"||str=="yes")   {
        write(BLINK HIG"�������һ���Ǳ�������˱չ�״̬!\n"NOR); 
        me->interrupt_me();
        return 1;
        }
        
        write(BLINK HIB"���Ҫ����չ�״̬�밴yes����y!\n");
        return 1;
}

     


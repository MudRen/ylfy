inherit ROOM;
void create()
{
        set("short", "�ɴ�");
        set("long", @LONG
һҶС�ۣ����Ҳ�������ߡ��˸��ˡ�һ����ʮ�����������
�ֳֳ���ݣ����ڴ�β�����س��Ŵ���
LONG
        );

        setup();
}
void run(object ob)
{
        if (environment(ob) == this_object())
        ob->move(__DIR__"duchuan3", 1);
//      write("\nС���ںɻ����л�������,��һ����俴��С���������ˡ�\n\n");
}

void init()
{
       object ob = this_player();

    call_out("run", 10, ob);
}

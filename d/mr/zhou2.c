inherit ROOM;
void create()
{
        set("short", "С��");
        set("long", @LONG
һҶС�ۣ����Ҳ�������ߡ��˸��ˡ�һ����ʮ������������ֳֳ���
�ݣ����ڴ�β�����س��Ŵ���
LONG
        );

        setup();
}
void run(object ob)
{
        if (environment(ob) == this_object())
        ob->move(__DIR__"zhou3", 1);
}

void init()
{
       object ob = this_player();

    call_out("run", 10, ob);
}

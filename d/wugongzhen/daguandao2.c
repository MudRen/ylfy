//daguandao2.c

inherit  ROOM;

void  create  ()
{
        set("short",  "��ٵ�");
        set("long",  @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ͨ�򺯹ȹأ�
������ֱ�ﳤ���ǡ�
LONG);
        set("exits",  ([  /*  sizeof()  ==  2  */
                "east"   :  __DIR__"hanguguan",
                "west"   :  __DIR__"daguandao",
        ]));

        set("outdoors",  1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}





//road1.c

inherit  ROOM;

void  create  ()
{
        set("short",  "�����");
        set("long",  @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ͨ��֬��֮
�������ݣ�������ֱ�ﳤ���ǡ�
LONG);
        set("exits",  ([  /*  sizeof()  ==  2  */
                "east"  :  "/d/quanzhen/zhuangjiadi2",
                "west"  :  __DIR__"hanguguan",
        ]));

        set("outdoors",  1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}



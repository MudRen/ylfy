//bye enter

inherit ROOM;

void create()
{
        set("short", "��ʯ��");
        set("long",@LONG
������һ����ʯ���ϣ�����С�ﾲ���ĵģ�������·��
�����龰��ȫ��һ�������ܾ��������е㲻�Ծ���
LONG
        );

        set("exits", ([
                "northeast" : __DIR__"chunxilu2",
                "east" : __DIR__"qingshixiang2",
            ]));
        setup();
        replace_program(ROOM);       
}



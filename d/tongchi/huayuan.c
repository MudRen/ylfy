inherit ROOM;
void create()
{
          set("short", "��԰");
        set("long", @LONG
������ͨ�԰�ĺ�԰����԰�������������¸��ص�����
�磺��ĵ��,�ջ���������ȵ�,������վ��һλ��������Ů��
���ڻ��ĳ�����,ɢ����һ���������׵����ʡ�
LONG
        );
        set("exits", ([
                   "south" : __DIR__"xiefj",
        ]));
        set("objects", ([
       __DIR__"npc/hanling" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

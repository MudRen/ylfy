inherit ROOM;
void create()
{
        set("short", "˽�̷�");
        set("long", @LONG
���������񷻱���Ϊ潵ĵط���ÿ�����Ͼͷ��Ĺ��ﶼ�ᱻ������������Ժȡ�
�绹���ӣ������̿���ǽ�Ϻ͵��϶��а���ɫ��Ѫ�����ݽ�һ�Ű����С��������
���ҵĴ������ƺ���������ҧ���ĺۼ���
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"sr2",
]));
       set("objects", ([
        __DIR__"npc/funu" : 2,
        __DIR__"obj/broken_cloth" : 2,
                        ]) );

        setup();
}

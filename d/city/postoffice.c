inherit ROOM;
void create()
{
	set("short", "������վ");
	set("long", @LONG
�����Ǹ������ݳǹٸ�����Ͱ��յ��ż��շ�����վ����վ���ſ���
����һ��ľ��(sign)������д��Щ�֡�
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "������֪��֮����Ϊ�����ż��շ����ң������ҷ����գ�\n"
           "�����ʼ�һ������շ�����������ask officer about mail��\n",
]));
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"beimen",
	]));
	set("objects", ([
		__DIR__"npc/post_officer": 1
	]) );
	setup();
}
int valid_leave(object me, string dir)
{
	object mbox;
	if( mbox = me->query_temp("mbox_ob") ) {
		tell_object(me, "�㽫���佻����վ��\n");
		destruct(mbox);
	}
	return 1;
}

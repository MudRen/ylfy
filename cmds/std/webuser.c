// webuser.c
// neva Ϊxserver ˫ͷ��ģʽ���������
// 2003��2��7��

inherit F_CLEAN_UP;


int main( object me )
{
	if( me->is_busy() )
		return notify_fail("�����һ��������δ���.\n");

	if( me->is_fighting() )
		return notify_fail("������ս����.\n");


	if( me->query("position") == "zmuduser") {
		me->set("position", "webuser");
		message_vision("$N �趨ʹ����ҳ�����������Ϸ��\n", me);
	} else if( me->query("position") == "webuser") {
		return notify_fail("���Ѿ��趨Ϊʹ����ҳ��������ӽ�����Ϸģʽ�ˡ�\n");
	} 
	return 1;
}

int help( object me)
{
	write(@HELP
ָ���ʽ: webuser
��ָ����ʹ����ҳ�����������Ϸ����ҿ��Կ�����������ʾ��

���ָ��: zmuduser
HELP
	);
        return 1;
}

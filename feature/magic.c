//ħ��ϵͳ

#include <ansi.h>

//ħ������(������me,������ob,����˺�damage)
int magic_parry(object me,object ob,int damage)
{
	int damage_magic;
if (damage > 0)
{
	switch(me->query("wuxing/mofa"))
	{
		case 0:
			if (ob->query("wuxing/mofa") == 8)
			{
				if (random(9) > 4)
				{
					damage_magic = damage*3/5;
					message_vision(NOR"\n$N�Ĺ���������$n�ĺڰ�������һ�ּ����ȶ�����̬�໥��ײ����.....\n"HIW"ͻȻ$N����ǿ��һ����$N�Ĺ��������ƺ�������$n�ĺڰ�������������$N��ǰ�γ�һ����֮���ϡ�\n"NOR,me,ob );
					tell_object(me, HIM"��Ĺ����������������"+damage*2/5+"���˺���\n"NOR);
				}
				else
				{
					damage_magic = damage*7/5;
					message_vision(NOR"\n$N�Ĺ���������$n�ĺڰ�������һ�ּ����ȶ�����̬�໥��ײ����.....\nͻȻ$n���ϵĺڰ���Ϣ��ø��������һ˿�����۳�һ��ϸ��ֱ����$N��ǰ�ء�\n"NOR,me,ob );
					tell_object(ob, HIM"��ĺڰ��������"+damage*2/5+"��Ķ����˺���\n"NOR);
				}
			}
			else
			{
				if (random(9) > 4)
				{
					damage_magic = damage*4/5;
					message_vision(HIW"\n$N����ͻȻ������ʣ�һ�������Ĺ�֮���ϵ���$N��ǰ��\n"NOR,me);
					tell_object(me, HIM"��Ĺ����������������"+damage*1/5+"���˺���\n"NOR);
				}
				else
				{
					damage_magic = damage;
				}
			}
			break;

		case 1:
			if (random(9) > 4)
			{
				if (ob->query("wuxing/mofa") == 2)
				{
					damage_magic = damage*3/5;
					message_vision(HIY"\n$N����ͻȻ�ƹ�һ������֮���ܳ�������$N��ǰ��\n"NOR,me);
					tell_object(me, HIM"��ĵ�֮�������������"+damage*2/5+"���˺���\n"NOR);
				}
				else if (ob->query("wuxing/mofa") == 4)
				{
					damage_magic = damage*7/5;
					message_vision(HIG"\n$n�������һ����$N���µ���ͻȻ�ѿ���һľ׮ֱֱײ��$N���̡�\n"NOR,me,ob);
					tell_object(ob, HIM"���ľ֮�������"+damage*2/5+"��Ķ����˺���\n"NOR);
				}
				else
				{
					damage_magic = damage*4/5;
					message_vision(HIY"\n$N����ͻȻ�ƹ�һ������֮�ܳ�������$N��ǰ��\n"NOR,me);
					tell_object(me, HIM"��ĵ�֮�������������"+damage*1/5+"���˺���\n"NOR);
				}
			}
			else
				damage_magic = damage;
			break;

		case 2:
			if (random(9) > 4)
			{
				if (ob->query("wuxing/mofa") == 4)
				{
					damage_magic = damage*3/5;
					message_vision(HIR"\n$N����ͻȻ���һ����$N��ǰƾ�ճ���һ����ǽ��\n"NOR,me);
					tell_object(me, HIM"��Ļ�֮�������������"+damage*2/5+"���˺���\n"NOR);
				}
				else if (ob->query("wuxing/mofa") == 3)
				{
					damage_magic = damage*7/5;
					message_vision(HIW"\n$n���ϰ׹�һ����ƾ�ճ���һ��ˮ����ֱ��$N��ȥ��\n"NOR,me,ob);
					tell_object(ob, HIM"���ˮ֮�������"+damage*2/5+"��Ķ����˺���\n"NOR);
				}
				else
				{
					damage_magic = damage*4/5;
					message_vision(HIR"\n$N����ͻȻ���һ����һ����֮���ϳ�����$N��ǰ��\n"NOR,me);
					tell_object(me, HIM"��Ļ�֮�������������"+damage*1/5+"���˺���\n"NOR);
				}
			}
			else
				damage_magic = damage;
			break;

		case 3:
			if (random(9) > 4)
			{
				if (ob->query("wuxing/mofa") == 10)
				{
					damage_magic = damage*3/5;
					message_vision(HIW"\n$N����ͻȻ�׹�һ����$N��ǰƾ�ճ���һ��ˮǽ��\n"NOR,me);
					tell_object(me, HIM"���ˮ֮�������������"+damage*2/5+"���˺���\n"NOR);
				}
				else if (ob->query("wuxing/mofa") == 1)
				{
					damage_magic = damage*7/5;
					message_vision(HIY"\n$n���ϻƹ�һ����$N���µ���ͻȻͻ���׶״����$n��\n"NOR,me,ob);
					tell_object(ob, HIM"�����֮�������"+damage*2/5+"��Ķ����˺���\n"NOR);
				}
				else
				{
					damage_magic = damage*4/5;
					message_vision(HIW"\n$N����ͻȻ�׹�һ����һ��ˮ֮���ϳ�����$N��ǰ��\n"NOR,me);
					tell_object(me, HIM"���ˮ֮�������������"+damage*1/5+"���˺���\n"NOR);
				}
			}
			else
				damage_magic = damage;
			break;

		case 4:
			if (random(9) > 4)
			{
				if (ob->query("wuxing/mofa") == 1)
				{
					damage_magic = damage*3/5;
					message_vision(HIG"\n$N����ͻȻ���һ����һ�Ų������������$N����ǰ��\n"NOR,me);
					tell_object(me, HIM"���ľ֮�������������"+damage*2/5+"���˺���\n"NOR);
				}
				else if (ob->query("wuxing/mofa") == 10)
				{
					damage_magic = damage*7/5;
					message_vision(HIY"\n$n���Ͻ�âһ����һ�Ž�ƾ�ճ��־�ֱ����$N��\n"NOR,me,ob);
					tell_object(ob, HIM"��Ľ�֮�������"+damage*2/5+"��Ķ����˺���\n"NOR);
				}
				else
				{
					damage_magic = damage*4/5;
					message_vision(HIG"\n$N����ͻȻ���һ����һ�ž�ľ������$N��ǰ��\n"NOR,me);
					tell_object(me, HIM"���ľ֮�������������"+damage*1/5+"���˺���\n"NOR);
				}
			}
			else
				damage_magic = damage;
			break;

		case 5:
			if (random(9) > 4)
			{
				damage_magic = damage*4/5;
				message_vision(NOR"\n$N����ӰͻȻ������ʣ�һ������ƾ�վ�����$N��Χ��\n"NOR,me);
				tell_object(me, HIM"�����֮�������������"+damage*1/5+"���˺���\n"NOR);
			}
			else
				damage_magic = damage;
			break;

		case 6:
			if (random(9) > 4)
			{
				damage_magic = damage*4/5;
				message_vision(HIB"\n$N���ϵ����˸��ǿ��ĵ�����$N��Χ�γ�һȦ�����Ĵų���硣\n"NOR,me);
				tell_object(me, HIM"�����֮�������������"+damage*1/5+"���˺���\n"NOR);
			}
			else
				damage_magic = damage;
			break;

		case 7:
			if (random(9) > 4)
			{
				damage_magic = damage*4/5;
				message_vision(HIM"\n$N��������һ�㵭������ɫ���Σ�һ�澫��֮����ͻȻ������$N��ǰ��\n"NOR,me);
				tell_object(me, HIM"��������������������"+damage*1/5+"���˺���\n"NOR);
			}
			else
				damage_magic = damage;
			break;

		case 8:
			if (ob->query("wuxing/mofa") == 0)
			{
				if (random(9) > 4)
				{
					damage_magic = damage*3/5;
					message_vision(NOR"\n$N�ĺڰ�������$n�Ĺ���������һ�ּ����ȶ�����̬�໥��ײ����.....\nͻȻ$N���Ϻڰ���Ϣ��ʢ��$N�ĺڰ�����������$n����������Լ����$N��Χ�γ�һ���ڰ���Ļ��\n"NOR,me,ob );
					tell_object(me, HIM"��ĺڰ��������������"+damage*2/5+"���˺���\n"NOR);
				}
				else
				{
					damage_magic = damage*7/5;
					message_vision(NOR"\n$N�ĺڰ�������$n�Ĺ���������һ�ּ����ȶ�����̬�໥��ײ����.....\nͻȻ$n����ǿ���ʢ��һ����֮��ָֻ$Nǰ�ء�\n"NOR,me,ob );
					tell_object(ob, HIM"��Ĺ����������"+damage*2/5+"��Ķ����˺���\n"NOR);
				}
			}
			else
			{
				if (random(9) > 4)
				{
					damage_magic = damage*4/5;
					message_vision(NOR"\n$N����ӰͻȻ���ģ���Ѽ���һ����ڵ�����������$N�����ܡ�\n"NOR,me);
					tell_object(me, HIM"��ĺڰ��������������"+damage*1/5+"���˺���\n"NOR);
				}
				else
				{
					damage_magic = damage;
				}
			}
			break;

		case 9:
			if (random(9) > 4)
			{
				damage_magic = damage*4/5;
				message_vision(HIC"\n$N������ͻȻƾ����ʧ��$Nԭ�����ڵ�λ�ü�Ȼ�γ�һ���޵Ŀռ�ϲ㡣\n"NOR,me);
				tell_object(me, HIM"��Ŀռ��������������"+damage*1/5+"���˺���\n"NOR);
			}
			else
				damage_magic = damage;
			break;

		case 10:
			if (random(9) > 4)
			{
				if (ob->query("wuxing/mofa") == 1)
				{
					damage_magic = damage*3/5;
					message_vision(HIY"\n$N����ͻȻ��âһ����$N����Ƥ����������ʻ�����������⡣\n"NOR,me);
					tell_object(me, HIM"��Ľ�֮�������������"+damage*2/5+"���˺���\n"NOR);
				}
				else if (ob->query("wuxing/mofa") == 2)
				{
					damage_magic = damage*7/5;
					message_vision(HIR"\n$n���Ϻ��һ����һ������ƾ�ճ��־�ֱ����$N��\n"NOR,me,ob);
					tell_object(ob, HIM"��Ļ�֮�������"+damage*2/5+"��Ķ����˺���\n"NOR);
				}
				else
				{
					damage_magic = damage*4/5;
					message_vision(HIY"\n$N����ͻȻ���һ����$N����Ƥ�����������ʻ������������⡣\n"NOR,me);
					tell_object(me, HIM"��Ľ�֮�������������"+damage*1/5+"���˺���\n"NOR);
				}
			}
			else
				damage_magic = damage;
			break;

			default:damage_magic = damage;
	}
	return damage_magic;
}
else
	return damage;
}
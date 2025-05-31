import { useState } from 'react';

export default function Pricing() {
    const [selected, setSelected] = useState('Plan Pro');

    const plans = [
        {
            title: 'Plan Start',
            price: '0 zł',
            newFeatures: ['Dodawanie części', 'Podstawowe wyszukiwanie', '1 magazyn'],
            inherits: null,
        },
        {
            title: 'Plan Pro',
            price: '49 zł / miesiąc',
            newFeatures: ['Zaawansowane filtry', 'Raporty i alerty', 'Do 5 magazynów'],
            inherits: 'Plan Start',
        },
        {
            title: 'Plan Biznes',
            price: '99 zł / miesiąc',
            newFeatures: ['Integracje API', 'Zarządzanie użytkownikami', 'Nieograniczona liczba magazynów'],
            inherits: 'Plan Pro',
        },
    ];

    return (
        <div className="max-w-6xl mx-auto px-6 py-16">
            <h1 className="text-4xl font-bold text-gray-800 mb-8 text-center">Cennik</h1>

            <p className="text-lg text-gray-700 mb-12 text-center max-w-2xl mx-auto">
                Wybierz plan, który najlepiej odpowiada Twoim potrzebom. Każdy kolejny plan zawiera wszystkie funkcje poprzedniego oraz dodatkowe rozszerzenia.
            </p>

            <div className="grid md:grid-cols-3 gap-8">
                {plans.map((plan) => (
                    <div
                        key={plan.title}
                        className={`rounded-lg shadow-md p-6 bg-white cursor-pointer transition-all border-2 flex flex-col items-center ${
                            selected === plan.title ? 'border-blue-600 scale-105' : 'border-transparent hover:border-blue-400'
                        }`}
                        onClick={() => setSelected(plan.title)}
                    >
                        <h2 className="text-xl font-semibold text-gray-800 mb-1">{plan.title}</h2>

                        <p className="text-sm text-gray-500 italic mb-2">
                            {plan.inherits
                                ? <>Zawiera wszystko z <strong>{plan.inherits}</strong>, plus:</>
                                : 'Podstawowy plan'}
                        </p>

                        <p className="text-3xl font-bold text-blue-600 mb-6">{plan.price}</p>

                        <ul className="space-y-2 text-sm mb-6 w-full">
                            {plan.newFeatures.map((feature, i) => (
                                <li key={i} className="text-gray-600 flex items-center gap-2">
                                    ➕ {feature}
                                </li>
                            ))}
                        </ul>

                        <button
                            className={`mt-auto px-6 py-2 rounded w-full transition text-white ${
                                selected === plan.title ? 'bg-blue-700' : 'bg-blue-600 hover:bg-blue-700'
                            }`}
                        >
                            {selected === plan.title ? 'Wybrano ten plan' : 'Wybierz plan'}
                        </button>
                    </div>
                ))}
            </div>

            <div className="text-center mt-12">
                <p className="text-gray-700 mb-4">Masz pytania lub potrzebujesz indywidualnej wyceny?</p>
                <a
                    href="/contact"
                    className="inline-block bg-indigo-600 hover:bg-indigo-700 text-white px-6 py-3 rounded-lg transition"
                >
                    Skontaktuj się z nami
                </a>
            </div>
        </div>
    );
}

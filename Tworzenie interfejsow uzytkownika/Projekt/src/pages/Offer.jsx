import { useState } from 'react';

export default function Offer() {
    const plans = [
        {
            id: 'basic',
            icon: '🧰',
            title: 'Plan Podstawowy',
            desc: 'Podstawowe funkcje magazynowe, dodawanie części, przeglądanie listy i stany magazynowe.',
        },
        {
            id: 'pro',
            icon: '📊',
            title: 'Plan Pro',
            desc: 'Zaawansowane raportowanie, integracje z systemami zewnętrznymi, alerty o niskim stanie.',
        },
        {
            id: 'enterprise',
            icon: '🏢',
            title: 'Plan Enterprise',
            desc: 'Dedykowane wsparcie, możliwość rozszerzeń, zarządzanie wieloma magazynami i użytkownikami.',
        },
    ];

    const [selected, setSelected] = useState('pro');

    return (
        <div className="max-w-5xl mx-auto px-6 py-16">
            <h1 className="text-4xl font-bold text-gray-800 mb-8 text-center">Nasza oferta</h1>

            <p className="text-lg text-gray-700 mb-12 text-center">
                Oferujemy kompleksowe rozwiązania do zarządzania magazynem części samochodowych.
                Dostosowane do małych warsztatów i dużych firm logistycznych.
            </p>

            <div className="grid md:grid-cols-3 gap-8">
                {plans.map((plan) => (
                    <div
                        key={plan.id}
                        onClick={() => setSelected(plan.id)}
                        className={`cursor-pointer bg-white p-6 rounded-lg shadow-md hover:shadow-xl transition-all transform hover:scale-105 text-center ${
                            selected === plan.id ? 'border-2 border-blue-600' : 'border border-gray-200'
                        }`}
                    >
                        <div className="text-4xl mb-4">{plan.icon}</div>
                        <h2 className="text-xl font-semibold text-blue-600 mb-2">{plan.title}</h2>
                        <p className="text-gray-600 text-sm mb-4">{plan.desc}</p>
                        <button
                            className={`${
                                selected === plan.id
                                    ? 'bg-blue-600 text-white'
                                    : 'bg-gray-200 text-gray-700 hover:bg-gray-300'
                            } px-4 py-2 rounded shadow`}
                        >
                            {selected === plan.id ? 'Wybrano' : 'Wybierz'}
                        </button>
                    </div>
                ))}
            </div>

            <div className="text-center mt-12">
                <p className="text-gray-700 mb-4">Potrzebujesz indywidualnej oferty?</p>
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
